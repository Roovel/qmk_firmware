#include QMK_KEYBOARD_H

#define _RECTANGLE 0
#define _WORK 1
#define _BOOT 2

enum encoder_names {
  _LEFT,
};

enum keycodes {
    F_WIN_LEFT = SAFE_RANGE,
    F_WIN_RIGHT,
    F_WIN_LEFT_DISPLAY,
    F_WIN_RIGHT_DISPLAY,
    F_WIN_TOP_LEFT,
    F_WIN_MAXIMISE,
    F_WIN_TOP_RIGHT,
    F_WIN_BOTTOM_LEFT,
    F_WIN_MINIMISE
};

enum tapdance {
    TD_WIN_BOTTOM_RIGHT_AND_BOOT,
    TD_DEPLOYMENT_END_MESSAGE,
    TD_DEPLOYMENT_BOOKMARK,
    TD_SPLASH_CONSOLE,
    TD_TICKET_THREAD_AND_ROOTLY,
    TD_TICKET_ISSUES,
    TD_BACKOFFICE_SEARCH,
    TD_BET_AMOUNT,
    TD_GL_AND_BET_AMOUNT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case F_WIN_LEFT:
            if (record->event.pressed) {
                register_code(KC_LOPT);
                register_code(KC_LCMD);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LOPT);
                unregister_code(KC_LCMD);
                unregister_code(KC_LEFT);
            }
        return false;

        case F_WIN_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LOPT);
                register_code(KC_LCMD);
                register_code(KC_RIGHT);
            } else {
                unregister_code(KC_LOPT);
                unregister_code(KC_LCMD);
                unregister_code(KC_RIGHT);
            }
        return false;

        case F_WIN_LEFT_DISPLAY:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LOPT);
                register_code(KC_LCMD);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LOPT);
                unregister_code(KC_LCMD);
                unregister_code(KC_LEFT);
            }
        return false;

        case F_WIN_RIGHT_DISPLAY:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LOPT);
                register_code(KC_LCMD);
                register_code(KC_RIGHT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LOPT);
                unregister_code(KC_LCMD);
                unregister_code(KC_RIGHT);
            }
        return false;

        case F_WIN_TOP_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LCMD);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LCMD);
                unregister_code(KC_LEFT);
            }
        return false;

        case F_WIN_MAXIMISE:
            if (record->event.pressed) {
                register_code(KC_LOPT);
                register_code(KC_LCMD);
                register_code(KC_F);
            } else {
                unregister_code(KC_LOPT);
                unregister_code(KC_LCMD);
                unregister_code(KC_F);
            }
        return false;

        case F_WIN_TOP_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LCMD);
                register_code(KC_RIGHT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LCMD);
                unregister_code(KC_RIGHT);
            }
        return false;

        case F_WIN_BOTTOM_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LCMD);
                register_code(KC_LSFT);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LCMD);
                unregister_code(KC_LSFT);
                unregister_code(KC_LEFT);
            }
        return false;

        case F_WIN_MINIMISE:
            if (record->event.pressed) {
                register_code(KC_LOPT);
                register_code(KC_LCMD);
                register_code(KC_M);
            } else {
                unregister_code(KC_LOPT);
                unregister_code(KC_LCMD);
                unregister_code(KC_M);
            }
        return false;
    }
    return true;
};

void td_win_bottom_right_and_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(
            SS_LCTL(SS_LGUI(SS_LSFT(SS_TAP(X_RIGHT))))
        );
        reset_tap_dance(state);
    } else if (state->count == 2) {
        layer_move(_BOOT);
        reset_tap_dance(state);
    }
}

void td_deployment_end_message(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(
            "Looks good, please finish the deployment "
            SS_LALT(SS_TAP(X_2))
            "margusm"
            SS_DELAY(300)
            SS_TAP(X_TAB)
            );
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING(
            "Looks good, please finish the deployment "
            SS_LALT(SS_TAP(X_2))
            "ralfmarkussuss"
            SS_DELAY(300)
            SS_TAP(X_TAB)
            );
        reset_tap_dance(state);
    } else if (state->count == 3) {
        SEND_STRING(
            "Looks good, please finish the deployment "
            SS_LALT(SS_TAP(X_2))
            );
        reset_tap_dance(state);
    }
}

void td_deployment_bookmark(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(
            SS_LGUI(SS_TAP(X_D) SS_DELAY(300))
            SS_TAP(X_RIGHT)
            SS_LALT(SS_LSFT(
                SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_RIGHT)))
            SS_TAP(X_BACKSPACE)
            SS_LGUI(SS_TAP(X_LEFT))
            SS_LALT(SS_TAP(X_DELETE))
            SS_TAP(X_DELETE)
            SS_LALT(SS_TAP(X_RIGHT) SS_TAP(X_DELETE) SS_TAP(X_DELETE) SS_TAP(X_DELETE))
            SS_TAP(X_DELETE)
            SS_TAP(X_SPACE)
            SS_TAP(X_ENTER)
            );
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING(
            SS_LGUI(SS_TAP(X_D) SS_DELAY(300))
            SS_TAP(X_RIGHT)
            SS_LALT(SS_LSFT(
                SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_RIGHT)))
            SS_TAP(X_BACKSPACE)
            SS_LGUI(SS_TAP(X_LEFT))
            SS_LALT(SS_TAP(X_DELETE))
            SS_TAP(X_DELETE)
            SS_LALT(SS_TAP(X_RIGHT) SS_TAP(X_DELETE) SS_TAP(X_DELETE))
            SS_TAP(X_ENTER)
            );
        reset_tap_dance(state);
    }
}

void td_splash_console(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("true");
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING(
            "disableUpdate" SS_DELAY(100)
            SS_TAP(X_TAB)
            "true" SS_DELAY(100)
            SS_TAP(X_TAB)
        );
        reset_tap_dance(state);
    }
}

void td_ticket_thread_and_rootly(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(
            SS_LALT(SS_TAP(X_8))
            SS_TAP(X_GRAVE)
            "Post"
            SS_TAP(X_SLASH)
            "deployment testing thread in Slack"
            SS_LSFT(SS_TAP(X_GRAVE))
            SS_RALT(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(500))
            SS_LGUI(SS_TAP(X_V))
            SS_LALT(SS_TAP(X_9))
            );
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING(
            "More information on corresponding incident page "
            SS_LALT(SS_TAP(X_8))
            SS_TAP(X_GRAVE)
            "Rootly link"
            SS_LSFT(SS_TAP(X_GRAVE))
            SS_RALT(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(500))
            SS_LGUI(SS_TAP(X_V))
            SS_LALT(SS_TAP(X_9))
            );
        reset_tap_dance(state);
    }
}

void td_ticket_issues(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(
            "No issues found during post"
            SS_TAP(X_SLASH)
            "deployment testing."
            );
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING(
            "Post"
            SS_TAP(X_SLASH)
            "deployment testing revealed ");
        reset_tap_dance(state);
    } else if (state->count == 3) {
        SEND_STRING(
            "No issues found during post"
            SS_TAP(X_SLASH)
            "release testing.");
        reset_tap_dance(state);
    }
}

void td_backoffice_search(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(
            SS_LCTL(SS_TAP(X_S SS_DELAY(300)))
            "RagOov \t"
            );
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING(
            SS_LCTL(SS_TAP(X_S SS_DELAY(300)))
            "oragnar \t"
            );
        reset_tap_dance(state);
    }
}

void td_bet_amount(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("0.1");
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING("1");
        reset_tap_dance(state);
    }
}

void td_gl_and_bet_amount(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("gl");
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING("5");
        reset_tap_dance(state);
    } else if (state->count == 3) {
        SEND_STRING("500");
        reset_tap_dance(state);
    }
}

void rectangle_encoder_clockwise(void) {
    SEND_STRING(
        SS_LGUI(SS_LALT(SS_TAP(X_RIGHT)))
        );
}

void rectangle_encoder_counter_clockwise(void) {
    SEND_STRING(
        SS_LGUI(SS_LALT(SS_TAP(X_LEFT)))
        );
}

void work_encoder_clockwise(void) {
    SEND_STRING(
        SS_TAP(X_F12)
        );
}

void work_encoder_counter_clockwise(void) {
    SEND_STRING(
        SS_LGUI(SS_TAP(X_LEFT) SS_DELAY(50))
        SS_LALT(SS_TAP(X_RIGHT) SS_TAP(X_RIGHT) SS_TAP(X_RIGHT) SS_DELAY(50))
        SS_LGUI(SS_LSFT(SS_TAP(X_RIGHT)) SS_DELAY(50))
        SS_TAP(X_BACKSPACE)
        SS_TAP(X_ENTER)
        );
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_WIN_BOTTOM_RIGHT_AND_BOOT] = ACTION_TAP_DANCE_FN(td_win_bottom_right_and_boot),
    [TD_DEPLOYMENT_END_MESSAGE] = ACTION_TAP_DANCE_FN(td_deployment_end_message),
    [TD_DEPLOYMENT_BOOKMARK] = ACTION_TAP_DANCE_FN(td_deployment_bookmark),
    [TD_SPLASH_CONSOLE] = ACTION_TAP_DANCE_FN(td_splash_console),
    [TD_TICKET_THREAD_AND_ROOTLY] = ACTION_TAP_DANCE_FN(td_ticket_thread_and_rootly),
    [TD_TICKET_ISSUES] = ACTION_TAP_DANCE_FN(td_ticket_issues),
    [TD_BACKOFFICE_SEARCH] = ACTION_TAP_DANCE_FN(td_backoffice_search),
    [TD_BET_AMOUNT] = ACTION_TAP_DANCE_FN(td_bet_amount),
    [TD_GL_AND_BET_AMOUNT] = ACTION_TAP_DANCE_FN(td_gl_and_bet_amount),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_RECTANGLE] = LAYOUT(
        TO(_WORK), F_WIN_LEFT_DISPLAY, F_WIN_RIGHT_DISPLAY,
        F_WIN_TOP_LEFT, F_WIN_MAXIMISE, F_WIN_TOP_RIGHT,
        F_WIN_BOTTOM_LEFT, QK_BOOT /*F_WIN_MINIMISE*/, TD(TD_WIN_BOTTOM_RIGHT_AND_BOOT)
    ),

    [_WORK] = LAYOUT(
        TO(_RECTANGLE), TD(TD_DEPLOYMENT_END_MESSAGE), TD(TD_DEPLOYMENT_BOOKMARK),
        TD(TD_SPLASH_CONSOLE), TD(TD_TICKET_THREAD_AND_ROOTLY), TD(TD_TICKET_ISSUES),
        TD(TD_BACKOFFICE_SEARCH), TD(TD_BET_AMOUNT), TD(TD_GL_AND_BET_AMOUNT)
    ),

    [_BOOT] = LAYOUT(
        TO(_RECTANGLE), TO(_RECTANGLE), TO(_RECTANGLE),
        TO(_RECTANGLE), TO(_RECTANGLE), TO(_RECTANGLE),
        TO(_RECTANGLE), TO(_RECTANGLE)/*RGB_TOG*/, QK_BOOT
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (layer_state_is(_RECTANGLE)) {
            if (clockwise) {
                rectangle_encoder_clockwise();
            } else {
                rectangle_encoder_counter_clockwise();
            }
        } else if (layer_state_is(_WORK)) {
            if (clockwise) {
                work_encoder_clockwise();
            } else {
                work_encoder_counter_clockwise();
            }
        } else if (layer_state_is(_BOOT)) {
            if (clockwise) {
                layer_move(_RECTANGLE);
            } else {
                layer_move(_RECTANGLE);
            }
        }
        return false;
    }
    return false;
}
