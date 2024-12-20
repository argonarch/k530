#include QMK_KEYBOARD_H
#include "../../variables.h"
#define LC_F20 LCTL_T(KC_F20)
#define W_SP   GUI_T(KC_SPC)

#define S_CL  C_S_T(KC_F22)

#define C_V  LCTL(KC_V)
#define C_X  LCTL(KC_X)
#define C_C  LCTL(KC_C)
#define C_S  LCTL(KC_S)
#define C_Y  LCTL(KC_Y)
#define C_Z  LCTL(KC_Z)
#define CS_V  C(S(KC_V))
#define CS_X  C(S(KC_X))
#define CS_C  C(S(KC_C))
#define CS_S  C(S(KC_S))
#define CS_Y  C(S(KC_Y))
#define CS_Z  C(S(KC_Z))
#define C_PRIOR C(S(KC_PGUP))
#define C_NEXT C(S(KC_PGDN))
#define C_SCLN LCTL_T(KC_SCLN)

#define O_CAG OSM(MOD_LCTL | MOD_LALT | MOD_LGUI)
#define O_CAGS OSM(MOD_LCTL | MOD_LALT | MOD_LGUI | MOD_LSFT)

#define FN_ENT LT(_FN,KC_ENT)
#define FN_F21 LT(_FN,KC_F21)

#define ESC_CON LT(_CON,KC_ESC)
#define TAB_NUM LT(_NUM,KC_TAB)
#define SYMBOL LT(_SYMBOL,KC_BSLS)
#define QWERT TG(_QWERTY)
#define N_ALT RALT(KC_N)
#define A_ALT RALT(KC_A)
#define O_ALT RALT(KC_O)
#define E_ALT RALT(KC_E)
#define U_ALT RALT(KC_U)
#define I_ALT RALT(KC_I)

#define QUE_ALT RALT(KC_SLASH)

#define S_BSLS S(KC_BSLS)
#define S_TAB S(KC_TAB)
#define S_GR S(KC_GRAVE)
#define S_ENT S(KC_ENT)
#define S_COL LSFT(KC_SCLN)
#define S_DEL SFT_T(KC_DEL)

#define A_RIGHT A(KC_RIGHT)
#define A_LEFT A(KC_LEFT)


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
    { KC_LALT, C_C,     C_V,     C_Z,     C_Y,     C_X,     KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_SLSH, KC_EQL,  KC_TILD, },
    { TAB_NUM, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_H,    KC_L,    KC_LBRC, KC_RBRC, SYMBOL,  },
    { ESC_CON, KC_A ,   KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_R,    KC_T,    KC_N,    KC_S,    KC_MINS, XXXXXXX, FN_ENT,  },
    { S_DEL,   XXXXXXX, KC_COLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX, KC_BSPC, },
    { LC_F20,  O_CAG,   FN_F21,  XXXXXXX, XXXXXXX, XXXXXXX, W_SP,    XXXXXXX, XXXXXXX, C_SCLN,  O_CAGS,  XXXXXXX, KC_RSFT, QWERT,   }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_QWERTY]={
    { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SLSH, KC_EQL,  _______, },
    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, _______, },
    { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, _______, },
    { S_DEL,   XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_BSPC, },
    { KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_LCTL, KC_RALT, XXXXXXX, KC_RGUI, QWERT,   }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_NUM]  = {
    { KC_ENT,  KC_1,    KC_2,    KC_3,    KC_PEQL, _______, _______, _______, _______, _______, _______, _______, KC_LCAP, KC_LNUM, },
    { _______, KC_4,    KC_5,    KC_6,    KC_0,    N_1,     P_1,     P_2,     P_3,     Mail_1,  Mail_C1, P_7,     Mail_4,  _______, },
    { KC_ESC,  KC_7,    KC_8,    KC_9,    KC_PDOT, N_2,     P_4,     P_5,     P_6,     Mail_2,  Mail_C2, P_8,     XXXXXXX, KC_ENT,  },
    { KC_LSFT, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, ID_1,    IP_1,    IP_2,    IP_0,    Mail_3,  Mail_C3, XXXXXXX, _______, },
    { KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_LCTL, KC_RALT, XXXXXXX, KC_F14,  KC_RGUI, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_CON]  = {
    { KC_F15,  KC_F13,  _______, _______, _______, _______, RGB_RMOD,RGB_MOD, RGB_TOG, RGB_SPD, RGB_SPI, RGB_VAD, RGB_VAI, _______, },
    { KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, KC_ENT,  KC_1,    KC_2,    KC_3,    KC_PEQL, _______, RESET,   KC_RSFT, },
    { _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_4,    KC_5,    KC_6,    KC_0,    _______, XXXXXXX, KC_ENT,  },
    { KC_LSFT, XXXXXXX, _______, C_PRIOR, C_NEXT,  _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PDOT, XXXXXXX, _______, },
    { KC_LCTL, KC_RALT, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_LCTL, KC_RALT, XXXXXXX, KC_F16,  KC_RGUI, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_FN]   = {
    { KC_F17,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_AMPR, },
    { KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_WH_L, G(KC_F), G(KC_G), G(KC_C), G(KC_H), KC_PSCR, KC_HOME, KC_END,  KC_PIPE, },
    { KC_ESC,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_R, G(KC_D), G(KC_R), G(KC_T), G(KC_N), KC_PGUP, KC_PGDN, XXXXXXX, _______, },
    { KC_LSFT, XXXXXXX, A_LEFT,  A_RIGHT, C_PRIOR, C_NEXT,  G(KC_X), G(KC_B), G(KC_M), G(KC_W), KC_INS,  KC_DEL,  XXXXXXX, _______, },
    { KC_LCTL, KC_LGUI, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_LCTL, KC_RALT, XXXXXXX, KC_F18,  KC_RGUI, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_SYMBOL]={
    { CS_X,    CS_C,    CS_V,    CS_Z,    CS_Y,    CS_S,    _______, _______, _______, _______, KC_PLUS, KC_PERC, KC_HASH, KC_DLR,  },
    { S_TAB,   KC_DQUO, KC_LABK, KC_RABK, KC_GRV,  _______, _______, _______, _______, _______, KC_UNDS, KC_LCBR, KC_RCBR, _______, },
    { _______, A_ALT,   O_ALT,   E_ALT,   U_ALT,   I_ALT,   _______, _______, _______, N_ALT,   KC_LPRN, KC_RPRN, XXXXXXX, S_ENT,   },
    { _______, XXXXXXX, KC_AT,   KC_CIRC, KC_ASTR, KC_EXLM, KC_PWR,  KC_SLEP, KC_WAKE, _______, QUE_ALT, KC_QUES, XXXXXXX, _______, },
    { KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, S_CL,    KC_F24,  XXXXXXX, KC_F23,  KC_RGUI, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
};
