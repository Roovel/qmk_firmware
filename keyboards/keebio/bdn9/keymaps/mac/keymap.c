
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum keycodes {
    F_WIN_LEFT = SAFE_RANGE,
    F_WIN_RIGHT,
    F_WIN_BOTTOM_RIGHT,
    F_WIN_TOP_RIGHT,
    F_WIN_BOTTOM_LEFT,
    F_WIN_TOP_LEFT,
    F_WIN_MINIMISE,
    F_WIN_MAXIMISE,
    F_WIN_LEFT_DISPLAY,
    F_WIN_RIGHT_DISPLAY
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case F_WIN_LEFT:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_1);
        } else {
            unregister_code(KC_1);
            unregister_code(KC_LSFT);
        }
        return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_MUTE, KC_HOME, KC_MPLY,
        MO(1)  , KC_UP  , RGB_MOD,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        QK_BOOT  , BL_STEP, KC_STOP,
        _______, KC_HOME, RGB_MOD,
        KC_MPRV, KC_END , KC_MNXT
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
