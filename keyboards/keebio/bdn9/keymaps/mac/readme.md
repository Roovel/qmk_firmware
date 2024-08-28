--GENERATE BIN--

cd qmk_firmware
make keebio/bdn9/rev2:mac

--FLASH BIN--

dfu-util -a 0 -d 0483:DF11 -s 0x8000000:leave -D keebio_bdn9_rev2_mac.bin


--MAC AND WINDOWS KEYS--

SS_LCTL(string) = left Ctrl
SS_LSFT(string) = left Shift
SS_LALT(string) = left Alt (Option key ⌥ on Mac)
SS_LGUI(string) = left GUI (Win key on Windows, Cmd key ⌘ on Mac)

KC_GRAVE and KC_NUBS are switched on my mac
