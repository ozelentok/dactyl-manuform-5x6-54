#include "keycodes.h"
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

const uint16_t PROGMEM combo_tab[] = {LSFT_T(KC_D), LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_alt_shift[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_alt_tab[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_gui_d[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_cw_toggle[] = {KC_M, KC_COMM, COMBO_END};

// clang-format off

combo_t key_combos[] = {
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_alt_shift, ALT_SHIFT),
    COMBO(combo_alt_tab, LALT(KC_TAB)),
    COMBO(combo_gui_d, LGUI(KC_D)),
    COMBO(combo_cw_toggle, CW_TOGG),
};


/* Layout
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,                                             KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,                                             KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,                                             KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,                                             KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
                                                                        KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,           KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
*/

#define BASE 0
#define NAV 1
#define SYM 2
#define MOUSE 3
#define GAME 4
#define GAME_S 5
#define MEDIA 6

#define U_RDO LCTL(KC_Y)
#define U_PST LCTL(KC_V)
#define U_CPY LCTL(KC_C)
#define U_CUT LCTL(KC_X)
#define U_UND LCTL(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_5x6_54(
    MO(MEDIA),       KC_1,            KC_2,            KC_3,            KC_4,            KC_5,                                                       KC_6,            KC_7,            KC_8,            KC_9,            KC_0,            KC_PSCR,
    KC_TAB,          KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                                                       KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,            KC_INSERT,
    KC_LSFT,         LALT_T(KC_A),    LGUI_T(KC_S),    LSFT_T(KC_D),    LCTL_T(KC_F),    KC_G,                                                       KC_H,            LCTL_T(KC_J),    LSFT_T(KC_K),    LGUI_T(KC_L),    LALT_T(KC_SCLN), KC_QUOT,
    KC_LCTL,         KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,                                                       KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_RCTL,
                                                                        LT(NAV, KC_TAB), LT(SYM, KC_SPC), LT(MOUSE, KC_ESC),      LT(MOUSE, KC_ENT), LT(SYM, KC_BSPC),  LT(NAV, KC_DEL)
  ),

  [NAV] = LAYOUT_5x6_54(
    _______,         LGUI(KC_1),      LGUI(KC_2),      LGUI(KC_3),      LGUI(KC_4),      LGUI(KC_5),                                                 LGUI(KC_6),      LGUI(KC_7),      LGUI(KC_8),      LGUI(KC_9),      LGUI(KC_0),      KC_PAUSE,
    _______,         U_RDO,           U_CUT,           U_PST,           U_CPY,           U_UND,                                                      _______,         KC_PGUP,         KC_HOME,         _______,         _______,         _______,
    _______,         KC_LALT,         KC_LGUI,         KC_LSFT,         KC_LCTL,         _______,                                                    KC_LEFT,         KC_DOWN,         KC_UP,           KC_RGHT,         _______,         _______,
    _______,         ALT_SHIFT,       _______,         KC_F11,          KC_F12,          _______,                                                    _______,         KC_PGDN,         KC_END,          _______,         CW_TOGG,         _______,
                                                                        KC_TAB,          KC_SPC,          KC_ESC,                 KC_ENT,            KC_BSPC,         KC_DEL
  ),

  [SYM] = LAYOUT_5x6_54(
    _______,         KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,                                                      KC_F6,           KC_F7,           KC_F8,           KC_F9,           KC_F10,          _______,
    _______,         _______,         KC_LABK,         KC_RABK,         KC_DQT,          KC_GRV,                                                     KC_AMPR,         KC_QUOT,         KC_LBRC,         KC_RBRC,         _______,         _______,
    _______,         KC_BSLS,         KC_EXLM,         KC_UNDS,         KC_MINS,         KC_PLUS,                                                    KC_PIPE,         KC_DLR,          KC_LPRN,         KC_RPRN,         KC_LALT,         _______,
    _______,         ALT_SHIFT,       KC_CIRC,         KC_ASTR,         KC_EQL,          KC_AT,                                                      KC_PERC,         KC_TILD,         KC_LCBR,         KC_RCBR,         CW_TOGG,         _______,
                                                                        KC_TAB,          KC_SPC,          KC_ESC,                 KC_ENT,            KC_BSPC,         KC_DEL
  ),

  [MOUSE] = LAYOUT_5x6_54(
    _______,         LGUI(KC_1),      LGUI(KC_2),      LGUI(KC_3),      LGUI(KC_4),      LGUI(KC_5),                                                 LGUI(KC_6),      LGUI(KC_7),      LGUI(KC_8),      LGUI(KC_9),      LGUI(KC_0),      QK_BOOT,
    _______,         _______,         KC_VOLD,         KC_VOLU,         KC_MUTE,         _______,                                                    _______,         KC_WH_U,         KC_MS_U,         _______,         _______,         _______,
    _______,         KC_LALT,         KC_LGUI,         KC_LSFT,         KC_LCTL,         _______,                                                    KC_MS_L,         KC_MS_L,         KC_MS_D,         KC_MS_R,         _______,         _______,
    _______,         ALT_SHIFT,       KC_MPLY,         KC_MPRV,         KC_MNXT,         _______,                                                    _______,         KC_WH_D,         _______,         _______,         CW_TOGG,         _______,
                                                                        KC_TAB,          KC_SPC,          KC_ESC,                 KC_BTN2,           KC_BTN1,         KC_BTN3
  ),

  [GAME] = LAYOUT_5x6_54(
    MO(MEDIA),       KC_1,            KC_2,            KC_3,            KC_4,            KC_5,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_TAB,          KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_LSFT,         KC_A,            KC_S,            KC_D,            KC_F,            KC_G,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_LCTL,         KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,                                                       _______,         _______,         _______,         _______,         _______,         _______,
                                                                        KC_LGUI,         KC_SPC,          LALT_T(KC_ESC),         _______,           _______,         _______
  ),
  /* Shifted WASD layout */
  [GAME_S] = LAYOUT_5x6_54(
    _______,         KC_1,            KC_2,            KC_3,            KC_4,            KC_5,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_T,            KC_TAB,          KC_Q,            KC_W,            KC_E,            KC_R,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_G,            KC_LSFT,         KC_A,            KC_S,            KC_D,            KC_F,                                                       _______,         _______,         _______,         _______,         _______,         _______,
    KC_B,            KC_LCTL,         KC_Z,            KC_X,            KC_C,            KC_V,                                                       _______,         _______,         _______,         _______,         _______,         _______,
                                                                        KC_LGUI,         KC_SPC,          LALT_T(KC_ESC),         _______,           _______,         _______
  ),

  [MEDIA] = LAYOUT_5x6_54(
    _______,         KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,                                                      KC_F6,           KC_F7,           KC_F8,           KC_F9,           KC_F10,          QK_BOOT,
    _______,         KC_VOLD,         KC_VOLU,         KC_MUTE,         TAB_AND_REFRESH, KC_F11,                                                     ALT_SHIFT,       KC_7,            KC_8,            KC_9,            _______,         _______,
    _______,         KC_MPLY,         KC_MPRV,         KC_MNXT,         PASTE_ENTER,     KC_F12,                                                     ALT_SHIFT,       KC_4,            KC_5,            KC_6,            _______,         _______,
    _______,         KC_F13,          KC_F14,          KC_F15,          KC_F16,          _______,                                                    _______,         KC_1,            KC_2,            KC_3,            CW_TOGG,         _______,
                                                                        TG(GAME),        TG(GAME_S),      _______,                _______,           KC_0,            _______
  )
};

// clang-format on
