#include QMK_KEYBOARD_H
#include "../../variables.h"

// Layer Temporal
#define TA_FN LT(_FN,KC_ENT)
#define TO_FN LT(_FN,KC_F21)
#define TO_CON LT(_CON,KC_ESC)
#define TO_NUM LT(_NUM,KC_TAB)

// Layer Switch
#define QWERT TG(_QWERTY)
#define CONT TG(_CON)

// One shot
#define HYPR_L OSM(MOD_LGUI | MOD_LALT)
#define HYPR_R OSM(MOD_LGUI | MOD_LCTL)
#define HYPR_O OSM(MOD_LGUI | MOD_LCTL | MOD_LALT)

// Modifier key
#define A_RIGHT A(KC_RIGHT)
#define A_LEFT A(KC_LEFT)
#define C_V  LCTL(KC_V)
#define C_A  LCTL(KC_A)
#define C_X  LCTL(KC_X)
#define C_C  LCTL(KC_C)
#define C_S  LCTL(KC_S)
#define C_Y  LCTL(KC_Y)
#define C_Z  LCTL(KC_Z)
#define C_PRIOR LCTL(KC_PGUP)
#define C_NEXT LCTL(KC_PGDN)

// Modifier Layer
#define ST_DEL SFT_T(KC_DEL)
#define ST_BSLS SFT_T(KC_BSLS)
#define LC_F20 LCTL_T(KC_F20)
#define C_SCLN LCTL_T(KC_SCLN)
#define W_SP   GUI_T(KC_SPC)
#define RA_TILD RALT_T(S(KC_GRV))

void matrix_init_user(void) {
  rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
};

enum layer_names {
  _BASE, _NUM, _CON, _FN, _QWERTY, _SYMBOL
};

enum custom_keycodes {
  P_1 = SAFE_RANGE,
  P_2, P_3, P_4, P_5, P_6, P_7, P_8,
  N_1, N_2, ID_1,
  Mail_1, Mail_2, Mail_3, Mail_4,
  Mail_C1, Mail_C2, Mail_C3,
  IP_0, IP_1, IP_2,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool send_oracion_enter(const char *my_str){
    if (record->event.pressed) {
      send_string(my_str);
      SEND_STRING(SS_TAP(X_ENT));
    }
    return false;
  }
  bool send_oracion(const char *my_str){
    if (record->event.pressed) {
      send_string(my_str);
    }
    return false;
  }
  switch (keycode) {
    case N_1: return send_oracion_enter(V_N_1); break;
    case N_2: return send_oracion_enter(V_N_2); break;
    case ID_1: return send_oracion_enter(V_ID_1); break;
    case P_1: return send_oracion_enter(V_P_1); break;
    case P_2: return send_oracion_enter(V_P_2); break;
    case P_3: return send_oracion_enter(V_P_3); break;
    case P_4: return send_oracion_enter(V_P_4); break;
    case P_5: return send_oracion_enter(V_P_5); break;
    case P_6: return send_oracion_enter(V_P_6); break;
    case P_7: return send_oracion_enter(G_C1); break;
    case P_8: return send_oracion_enter(G_C2); break;
    case Mail_1: return send_oracion(V_Mail_1); break;
    case Mail_2: return send_oracion(V_Mail_2); break;
    case Mail_3: return send_oracion(V_Mail_3); break;
    case Mail_4: return send_oracion(V_Mail_4); break;
    case Mail_C1: return send_oracion(V_Mail_C1); break;
    case Mail_C2: return send_oracion(V_Mail_C2); break;
    case Mail_C3: return send_oracion(V_Mail_C3); break;
    case IP_1: return send_oracion(V_IP_1); break;
    case IP_2: return send_oracion(V_IP_2); break;
    case IP_0: return send_oracion(V_IP_0); break;
  } return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*    0        1        2        3        4        5        6        7        8        9        10       11       12       13      */
  [_BASE] = {
    { KC_LALT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_SLSH, KC_EQL,  RA_TILD, },
    { TO_NUM,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_H,    KC_L,    KC_LBRC, KC_RBRC, ST_BSLS, },
    { TO_CON,  KC_A ,   KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_R,    KC_T,    KC_N,    KC_S,    KC_MINS, XXXXXXX, TA_FN,   },
    { ST_DEL,  XXXXXXX, KC_COLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX, KC_BSPC, },
    { LC_F20,  HYPR_L,  TO_FN,   XXXXXXX, XXXXXXX, XXXXXXX, W_SP,    XXXXXXX, XXXXXXX, C_SCLN,  HYPR_R,  XXXXXXX, HYPR_O,  QWERT,   }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_QWERTY]={
    { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SLSH, KC_EQL,  _______, },
    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, _______, },
    { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, _______, },
    { ST_DEL,  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_BSPC, },
    { KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_LCTL, KC_RALT, XXXXXXX, KC_RGUI, QWERT,   }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_NUM]  = {
    { KC_LALT, KC_1,    KC_2,    KC_3,    KC_PEQL, _______, RGB_RMOD,RGB_MOD, RGB_TOG, RGB_SPD, RGB_SPI, RGB_VAD, RGB_VAI, KC_LNUM, },
    { _______, KC_4,    KC_5,    KC_6,    KC_0,    N_1,     P_1,     P_2,     P_3,     Mail_1,  Mail_C1, P_7,     Mail_4,  KC_LCAP, },
    { KC_ESC,  KC_7,    KC_8,    KC_9,    KC_PDOT, N_2,     P_4,     P_5,     P_6,     Mail_2,  Mail_C2, P_8,     XXXXXXX, KC_ENT,  },
    { KC_F13,  XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, ID_1,    IP_1,    IP_2,    IP_0,    Mail_3,  Mail_C3, XXXXXXX, _______, },
    { KC_F14,  KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_F15,  XXXXXXX, XXXXXXX, KC_F16,  KC_F17,  XXXXXXX, KC_F18,  KC_F19, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_CON]  = {
    { C_X,     C_C,     C_V,     C_Z,     C_Y,     _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______, },
    { C_S,     KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, KC_1,    KC_2,    KC_3,    KC_PEQL, _______, RESET,   KC_RSFT, },
    { _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_4,    KC_5,    KC_6,    KC_0,    _______, XXXXXXX, KC_ENT,  },
    { KC_LSFT, XXXXXXX, C_A,     C_PRIOR, C_NEXT,  _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PDOT, XXXXXXX, _______, },
    { KC_LCTL, KC_RALT, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_LCTL, KC_RALT, XXXXXXX, CONT,    KC_RGUI, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_FN]   = {
    { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_AMPR, },
    { KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_WH_L, G(KC_F), G(KC_G), G(KC_C), G(KC_H), KC_PSCR, KC_HOME, KC_END,  KC_PIPE, },
    { KC_ESC,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_R, G(KC_D), G(KC_R), G(KC_T), G(KC_N), KC_PGUP, KC_PGDN, XXXXXXX, _______, },
    { KC_LSFT, XXXXXXX, A_LEFT,  A_RIGHT, C_PRIOR, C_NEXT,  G(KC_X), G(KC_B), G(KC_M), G(KC_W), KC_INS,  KC_DEL,  XXXXXXX, _______, },
    { KC_LCTL, KC_LGUI, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_LCTL, KC_RALT, XXXXXXX, KC_F20,  KC_RGUI, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
};
