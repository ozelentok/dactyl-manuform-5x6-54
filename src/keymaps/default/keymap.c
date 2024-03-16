#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum custom_keycodes {
  ALT_SHIFT = SAFE_RANGE,
  TAB_AND_REFRESH,
  PASTE_ENTER,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case ALT_SHIFT:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LSFT)));
    }
    break;
  case TAB_AND_REFRESH:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("\t"));
      _delay_ms(100);
      SEND_STRING(SS_LSFT("e"));
    }
    break;
  case PASTE_ENTER:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("v") SS_TAP(X_ENTER));
    }
    break;
  }
  return true;
};

// clang-format off

/* Layout
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,                                             KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,                                             KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,                                             KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,                                             KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
                                                                        KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,           KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
*/

#define BASE 0
#define GAME 1
#define SYM 2
#define MEDIA 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_5x6_54(
    MO(MEDIA),       KC_1,            KC_2,            KC_3,            KC_4,            KC_5,                                                       KC_6,            KC_7,            KC_8,            KC_9,            KC_0,            KC_PSCR,
    KC_TAB,          KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                                                       KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,            KC_INSERT,
    KC_LSFT,         LALT_T(KC_A),    LGUI_T(KC_S),    LSFT_T(KC_D),    LCTL_T(KC_F),    KC_G,                                                       KC_H,            LCTL_T(KC_J),    LSFT_T(KC_K),    LGUI_T(KC_L),    LALT_T(KC_SCLN), KC_QUOT,
    KC_LCTL,         KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,                                                       KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_RCTL,
                                                                        KC_LGUI,         LT(SYM, KC_SPC), LSFT_T(KC_ESC),           KC_ENT,          LT(SYM, KC_BSPC),LSFT_T(KC_DEL)
  ),

  [GAME] = LAYOUT_5x6_54(
    _______,         KC_1,            KC_2,            KC_3,            KC_4,            KC_5,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    _______,         KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    _______,         KC_A,            KC_S,            KC_D,            KC_F,            KC_G,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    _______,         KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,                                                       _______,         _______,         _______,         _______,         _______,         _______,
                                                                        _______,         KC_SPC,          LALT_T(KC_ESC),           _______,         _______,         _______
    /* Experimental shifted WASD layout
    _______,         KC_1,            KC_2,            KC_3,            KC_4,            KC_5,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_T,            KC_TAB,          KC_Q,            KC_W,            KC_E,            KC_R,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_G,            KC_LSFT,         KC_A,            KC_S,            KC_D,            KC_F,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_B,            KC_LCTL,         KC_Z,            KC_X,            KC_C,            KC_V,                                                       _______,         _______,         _______,         _______,         _______,         _______,
                                                                        _______,         KC_SPC,          LALT_T(KC_ESC),           _______,         _______,         _______
    */
  ),

  [SYM] = LAYOUT_5x6_54(
    _______,         KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,                                                      KC_F6,           KC_F7,           KC_F8,           KC_F9,           KC_F10,          KC_CAPS,
    _______,         KC_F11,          KC_F12,          KC_EXCLAIM,      KC_DQT,          CW_TOGG,                                                    ALT_SHIFT,       KC_QUOT,         KC_LBRC,         KC_RBRC,         KC_PIPE,         KC_INSERT,
    _______,         LALT_T(KC_TAB),  LGUI_T(KC_TAB),  LSFT_T(KC_GRAVE),LCTL_T(KC_MINUS),KC_UNDS,                                                    KC_LEFT,         LCTL_T(KC_DOWN), LSFT_T(KC_UP),   LGUI_T(KC_RIGHT),LALT_T(KC_BSLS), _______,
    _______,         _______,         _______,         KC_TILD,         KC_EQL,          KC_PLUS,                                                    KC_HOME,         KC_PGDN,         KC_PGUP,         KC_END,          KC_PIPE,         KC_PAUSE,
                                                                        KC_TAB,          _______,          KC_TAB,                  _______,         KC_TAB,          _______
  ),

  [MEDIA] = LAYOUT_5x6_54(
    _______,         KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,                                                      KC_F6,           KC_F7,           KC_F8,           KC_F9,           KC_F10,          KC_F11,
    _______,         KC_VOLD,         KC_VOLU,         KC_MUTE,         TAB_AND_REFRESH, KC_F12,                                                     ALT_SHIFT,       KC_7,            KC_8,            KC_9,            _______,         _______,
    _______,         KC_MPLY,         KC_MPRV,         KC_MNXT,         PASTE_ENTER,     _______,                                                    _______,         KC_4,            KC_5,            KC_6,            _______,         _______,
    _______,         KC_F13,          KC_F14,          KC_F15,          KC_F16,          _______,                                                    _______,         KC_1,            KC_2,            KC_3,            _______,         _______,
                                                                        TG(GAME),        _______,         QK_BOOT,                  QK_BOOT,         KC_0,            TG(SYM)
  )
};

// clang-format on
