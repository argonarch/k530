#include QMK_KEYBOARD_H
#include "../../variables.h"
// #include "../../oneshot.h"

// Layer Temporal
#define TA_FNC LT(_FNC,KC_ENT)
#define TO_SYM LT(_SYM,KC_BSLS)
#define TO_FN LT(_FN,KC_BSPC)
#define TO_CON LT(_CON,KC_ESC)
#define TO_PASS LT(_PASS,KC_TAB)
#define TM_MUG LT(_MUD,KC_SPC)
#define TM_MUA LT(_MUD,KC_LALT)
#define TM_MUC LT(_MUD,KC_CAPS)
#define TM_MUCS LT(_MUD,KC_F21)

// Layer Switch
#define QWERT TG(_QWER)
#define CONT TG(_CON)

// One shot
// #define HYPR_L OSM(MOD_LGUI | MOD_LALT)
// #define HYPR_R OSM(MOD_LGUI | MOD_LCTL)
// #define HYPR_O OSM(MOD_LGUI | MOD_LCTL | MOD_LALT)
#define HYPR_L LT(_MUD, KC_F22)
#define HYPR_R LT(_MUD, KC_F23)
#define HYPR_O LT(_MUD, KC_F24)

// Modifier key
#define A_RIGHT A(KC_RIGHT)
#define A_LEFT A(KC_LEFT)
#define C_V  C(KC_V)
#define C_W  C(KC_W)
#define C_A  C(KC_A)
#define C_X  C(KC_X)
#define C_C  C(KC_C)
#define C_S  C(KC_S)
#define C_Y  C(KC_Y)
#define C_Z  C(KC_Z)
#define C_PRIOR C(KC_PGUP)
#define C_NEXT C(KC_PGDN)


#define CS_V  RCS(KC_V)
#define CS_A  RCS(KC_A)
#define CS_X  RCS(KC_X)
#define CS_C  RCS(KC_C)
#define CS_S  RCS(KC_S)
#define CS_Y  RCS(KC_Y)
#define CS_Z  RCS(KC_Z)

#define S_MPRV  S(KC_MPRV)
#define S_MNXT  S(KC_MNXT)
#define S_VOLD  S(KC_VOLD)
#define S_VOLU  S(KC_VOLU)
#define S_MPLY  S(KC_MPLY)

// Custom OneShot
// #define L_NAV   MO(_NAV)
// #define L_SYM   MO(_SYM)

// Modifier Layer
#define ST_KC SFT_T(KC_DEL)
#define RA_KC RALT_T(KC_TILD)
#define ST_BSLS SFT_T(KC_BSLS)
#define C_SCLN LCTL_T(KC_SCLN)

void matrix_init_user(void) {
  rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
};

enum layer_names {
  _BASE, _CON, _PASS, _FN, _QWER, _SYM, _FNC, _MUD,
};

enum custom_keycodes {
  P_1 = SAFE_RANGE,
  P_2, P_3, P_4, P_5, P_6, P_7, P_8,
  N_1, N_2, ID_1,
  Mail_1, Mail_2, Mail_3, Mail_4,
  Mail_C1, Mail_C2, Mail_C3, Mail_C4,
  IP_0, IP_1, IP_2,
  // OS_ALT, OS_GUI, OS_SFT, 
};

// bool is_oneshot_cancel_key(uint16_t keycode) {
//     switch (keycode) {
//     case L_SYM:
//     case L_NAV:
//         return true;
//     default:
//         return false;
//     }
// }
//
// bool is_oneshot_layer_cancel_key(uint16_t keycode) {
//     switch (keycode) {
//     case L_SYM:
//     case L_NAV:
//         return true;
//     default:
//         return false;
//     }
// }
//
// bool is_oneshot_ignored_key(uint16_t keycode) {
//     switch (keycode) {
//     case L_SYM:
//     case L_NAV:
//     case OS_CTRL:
//     case OS_ALT:
//     case OS_GUI:
//     case OS_SFT:
//         return true;
//     default:
//         return false;
//     }
// }
//
// bool is_oneshot_mod_key(uint16_t keycode) {
//     switch (keycode) {
//     case OS_CTRL:
//     case OS_ALT:
//     case OS_GUI:
//     case OS_SFT:
//         return true;
//     default:
//         return false;
//     }
// }
//
// oneshot_state os_ctrl_state = os_up_unqueued;
// oneshot_state os_alt_state = os_up_unqueued;
// oneshot_state os_cmd_state = os_up_unqueued;
// oneshot_state os_sft_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // update_oneshot(
  //     &os_ctrl_state, KC_LCTL, OS_CTRL,
  //     keycode, record
  // );
  // update_oneshot(
  //     &os_alt_state, KC_LALT, OS_ALT,
  //     keycode, record
  // );
  // update_oneshot(
  //     &os_cmd_state, KC_LGUI, OS_GUI,
  //     keycode, record
  // );
  // update_oneshot(
  //     &os_sft_state, KC_LSFT, OS_SFT,
  //     keycode, record
  // );

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

  bool layer_mod_kc(int modifs){
    if (record->tap.count == 0) {       
      if (record->event.pressed) {     
        register_mods(modifs); 
      } else {                         
        unregister_mods(modifs); 
      }
    }
    return true;
  }

  switch (keycode) {
    case N_1: return send_oracion_enter(V_N_1);
    case N_2: return send_oracion_enter(V_N_2);
    case ID_1: return send_oracion_enter(V_ID_1);
    case P_1: return send_oracion_enter(V_P_1);
    case P_2: return send_oracion_enter(V_P_2);
    case P_3: return send_oracion_enter(V_P_3);
    case P_4: return send_oracion_enter(V_P_4);
    case P_5: return send_oracion_enter(V_P_5);
    case P_6: return send_oracion_enter(V_P_6);
    case P_7: return send_oracion_enter(G_C1);
    case P_8: return send_oracion_enter(G_C2);
    case Mail_1: return send_oracion(V_Mail_1);
    case Mail_2: return send_oracion(V_Mail_2);
    case Mail_3: return send_oracion(V_Mail_3);
    case Mail_4: return send_oracion(V_Mail_4);
    case Mail_C1: return send_oracion(V_Mail_C1);
    case Mail_C2: return send_oracion(V_Mail_C2);
    case Mail_C3: return send_oracion(V_Mail_C3);
    case Mail_C4: return send_oracion(V_Mail_C4);
    case IP_1: return send_oracion(V_IP_1);
    case IP_2: return send_oracion(V_IP_2);
    case IP_0: return send_oracion(V_IP_0);
    case TM_MUG: return layer_mod_kc(MOD_LGUI);
    case TM_MUC: return layer_mod_kc(MOD_LCTL);
    case TM_MUCS: return layer_mod_kc(MOD_LCTL | MOD_LSFT);
    case TM_MUA: return layer_mod_kc(MOD_LALT);
    case HYPR_L: return layer_mod_kc(MOD_LGUI | MOD_LALT);
    case HYPR_R: return layer_mod_kc(MOD_LGUI | MOD_LCTL);
    case HYPR_O: return layer_mod_kc(MOD_LGUI | MOD_LCTL | MOD_LALT);
  } return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*    0        1        2        3        4        5        6        7        8        9        10       11       12       13      */
  [_BASE] = {
    { TM_MUA,  C_C,     C_V,     C_Z,     C_Y,     C_X,     KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_SLSH, KC_EQL,  RA_KC,   },
    { TO_PASS, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_H,    KC_L,    KC_LBRC, KC_RBRC, TO_SYM,  },
    { TO_CON,  KC_A ,   KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_R,    KC_T,    KC_N,    KC_S,    KC_MINS, XXXXXXX, TA_FNC,  },
    { ST_KC,   XXXXXXX, KC_COLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX, TO_FN,   },
    { TM_MUCS, HYPR_L,  TM_MUC,  XXXXXXX, XXXXXXX, XXXXXXX, TM_MUG,  XXXXXXX, XXXXXXX, C_SCLN,  HYPR_R,  XXXXXXX, HYPR_O,  QWERT,   }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_MUD] = {
    { KC_LALT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SLSH, KC_EQL,  KC_GRV,  },
    { KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_H,    KC_L,    KC_LBRC, KC_RBRC, TO_SYM,  },
    { TO_CON,  KC_A ,   KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_R,    KC_T,    KC_N,    KC_S,    KC_MINS, XXXXXXX, TA_FNC,  },
    { KC_LSFT, XXXXXXX, KC_COLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX, KC_BSPC, },
    { KC_LCTL, XXXXXXX, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_SYM]  = {
    { KC_LALT, CS_C,    CS_V,    CS_Z,    CS_Y,    CS_X,    S_MPRV,  S_MNXT,  S_VOLD,  S_VOLU,  S_MPLY,  KC_QUES, KC_PLUS, KC_TILD, },
    { KC_RALT, KC_DQUO, KC_LABK, KC_RABK, KC_ASTR, _______, _______, _______, _______, _______, KC_LPRN, KC_LCBR, KC_RCBR, _______, },
    { KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_CIRC, _______, _______, _______, _______, KC_RPRN, KC_UNDS, XXXXXXX, _______, },
    { KC_LSFT, XXXXXXX, KC_SCLN, KC_PERC, KC_PIPE, KC_AMPR, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, },
    { KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_RCTL, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_PASS]  = {
    { KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
    { _______, P_1,     P_2,     P_3,     P_4,     _______, _______, _______, _______, Mail_3,  Mail_C3, _______, _______, _______, },
    { KC_ESC,  P_5,     P_6,     P_7,     P_8,     _______, _______, Mail_1,  Mail_C1, Mail_2,  Mail_C2, _______, XXXXXXX, _______, },
    { _______, XXXXXXX, IP_1,    IP_2,    IP_0,    _______, _______, _______, _______, _______, Mail_4,  Mail_C4, XXXXXXX, _______, },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_CON]  = {
    { _______, _______, _______, _______, _______, _______, _______, _______, KC_PAST, KC_PMNS, KC_PEQL, _______, _______, RESET,   },
    { _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  C_PRIOR, KC_PPLS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______, _______, _______, },
    { _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, C_NEXT,  KC_PMNS, KC_4,    KC_5,    KC_6,    KC_0,    _______, XXXXXXX, _______, },
    { KC_LSFT, XXXXXXX, A_LEFT,  A_RIGHT, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PDOT, XXXXXXX, _______, },
    { KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_FN]   = {
    { _______, _______, KC_WH_L, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, RGB_RMOD,RGB_MOD, RGB_TOG, },
    { KC_BTN3, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, C_PRIOR, G(KC_F), G(KC_G), G(KC_C), G(KC_H), RGB_SPD, RGB_SPI, RGB_VAD, RGB_VAI, },
    { XXXXXXX, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, C_NEXT,  G(KC_D), G(KC_R), G(KC_T), G(KC_N), _______, RESET,   XXXXXXX, _______, },
    { KC_BSPC, XXXXXXX, A_LEFT,  A_RIGHT, _______, _______, G(KC_X), G(KC_B), G(KC_M), G(KC_W), _______, _______, XXXXXXX, _______, },
    { XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_FNC]  = {
    { KC_LALT, KC_F13,  KC_F14,  KC_F15,  KC_F16,  _______, _______, _______, _______, _______, KC_F17,  KC_F18,  KC_F19,  KC_F20,  },
    { KC_RALT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, C_PRIOR, KC_PSCR, KC_HOME, KC_END,  _______, },
    { KC_LGUI, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, C_W,     C_NEXT,  KC_PGUP, KC_PGDN, XXXXXXX, _______, },
    { KC_LSFT, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_INS,  KC_DEL,  XXXXXXX, _______, },
    { KC_LCTL, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_RCTL, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/
  [_QWER]={
    { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SLSH, KC_EQL,  _______, },
    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, _______, },
    { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, _______, },
    { KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_BSPC, },
    { KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, KC_LCTL, KC_RALT, XXXXXXX, KC_RGUI, QWERT,   }, },
    /*------------------------------------------------------------------------------------------------------------------------------*/ 
};
