#include QMK_KEYBOARD_H
#include "../../variables.h"
#define ESC_CON LT(_CON,KC_ESC)
#define TAB_NUM LT(_NUM,KC_TAB)
#define S_CAPS SFT_T(KC_CAPS)
#define LC_F20 LCTL_T(KC_F20)
#define LSA_P  RALT_T(KC_SCLN)
#define S_COL  LSFT(KC_SCLN)
#define W_SP   GUI_T(KC_SPC)
#define C_V  RCTL(KC_V)
#define C_X  RCTL(KC_X)
#define C_C  RCTL(KC_C)
#define C_S  RCTL(KC_S)
#define C_Y  RCTL(KC_Y)
#define C_Z  RCTL(KC_Z)
#define C_DEL RCTL_T(KC_BTN3)
#define CS_B RCS_T(KC_BSLS)
#define OLCAG OSM(MOD_LCTL | MOD_LALT | MOD_LGUI)
#define OHYPR OSM(MOD_HYPR)
#define RS_G RSFT_T(KC_GRV)
#define FN_ENT LT(_FN,KC_ENT)
#define QWERT TG(_QWERTY)

#define S_0 S(KC_0)
#define S_4 S(KC_4)
#define S_9 S(KC_9)
#define S_GR S(KC_GRAVE)

void matrix_init_user(void) {
  rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
};

enum layer_names {
    _BASE, _NUM, _CON, _FN, _QWERTY,
};

enum custom_keycodes {
    P_1 = SAFE_RANGE,
    P_2, P_3, P_4, P_5, P_6,
    N_1, N_2, ID_1,
    Mail_1, Mail_2, Mail_3,
    Mail_C1, Mail_C2, Mail_C3,
    IP_0, IP_1, IP_2,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool send_oracion_enter(const char *my_str){
        if (record->event.pressed) {
            send_string(my_str);
            SEND_STRING(SS_TAP(X_ENT));
        } return true;
    }
    bool send_oracion(const char *my_str){
        if (record->event.pressed) {
            send_string(my_str);
        } return true;
    }
    switch (keycode) {
        case N_1: send_oracion_enter(V_N_1); break;
        case N_2: send_oracion_enter(V_N_2); break;
        case ID_1: send_oracion_enter(V_ID_1); break;
        case P_1: send_oracion_enter(V_P_1); break;
        case P_2: send_oracion_enter(V_P_2); break;
        case P_3: send_oracion_enter(V_P_3); break;
        case P_4: send_oracion_enter(V_P_4); break;
        case P_5: send_oracion_enter(V_P_5); break;
        case P_6: send_oracion_enter(V_P_6); break;
        case Mail_1: send_oracion(V_Mail_1); break;
        case Mail_2: send_oracion(V_Mail_2); break;
        case Mail_3: send_oracion(V_Mail_3); break;
        case Mail_C1: send_oracion(V_Mail_C1); break;
        case Mail_C2: send_oracion(V_Mail_C2); break;
        case Mail_C3: send_oracion(V_Mail_C3); break;
        case IP_1: send_oracion(V_IP_1); break;
        case IP_2: send_oracion(V_IP_2); break;
        case IP_0: send_oracion(V_IP_0); break;
    } return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
         /*  Row:      0         1         2         3         4         5         6         7         8         9         10        11        12        13    */
    [_BASE] = { {   C_X,      C_C,      C_V,      C_Z,      C_Y,      C_S,      KC_MPRV,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY,  KC_SLSH,  KC_EQL,   CS_B,    },
                {   TAB_NUM,  KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_H,     KC_L,     KC_LBRC,  KC_RBRC,  RS_G,    },
                {   ESC_CON,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_R,     KC_T,     KC_N,     KC_S,     KC_MINS,  XXXXXXX,  FN_ENT,  },
                {   S_CAPS,   XXXXXXX,  S_COL,    KC_Q,     KC_X,     KC_K,     KC_J,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     XXXXXXX,  KC_BSPC, },
                {   LC_F20,   LSA_P,    KC_LALT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  W_SP,     XXXXXXX,  XXXXXXX,  C_DEL,    QWERT,    XXXXXXX,  OHYPR,    OLCAG,   }, },
               /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    [_QWERTY] = { { KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_SLSH,  KC_EQL,   _______, },
                {   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  _______,  },
                {   KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  XXXXXXX,  KC_ENT,  },
                {   S_CAPS,   XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,  KC_BSPC, },
                {   KC_LCTL,  LSA_P,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SPC,   XXXXXXX,  XXXXXXX, C_DEL,    QWERT,    XXXXXXX,  OHYPR,    OLCAG,   }, },
               /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    [_NUM]  = { {   KC_NO,    KC_1,     KC_2,     KC_3,     KC_PEQL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, },
                {   _______,  KC_4,     KC_5,     KC_6,     KC_0,     N_1,      P_1,      P_2,      P_3,      Mail_1,   Mail_C1,  _______,  _______,  KC_RSFT, },
                {   KC_ESC,   KC_7,     KC_8,     KC_9,     KC_PDOT,  N_2,      P_4,      P_5,      P_6,      Mail_2,   Mail_C2,  _______,  XXXXXXX,  KC_ENT,  },
                {   KC_LSFT,  XXXXXXX,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  ID_1,     IP_1,     IP_2,     IP_0,     Mail_3,   Mail_C3,  XXXXXXX,  _______, },
                {   KC_LCTL,  KC_RALT,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SPC,   XXXXXXX,  XXXXXXX,  KC_RCTL,  _______,  XXXXXXX,  KC_NO,    _______, }, },
               /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    [_CON]  = { {   KC_NO,    _______,  _______,  _______,  _______,  _______,  RGB_RMOD, RGB_MOD,  RGB_TOG,  RGB_SPD,  RGB_SPI,  RGB_VAD,  RGB_VAI,  _______, },
                {   KC_TAB,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  _______,  _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_PEQL,  _______,  RESET,    KC_RSFT, },
                {   _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  _______,  _______,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_0,  _______,  XXXXXXX,  KC_ENT,  },
                {   KC_LSFT,  XXXXXXX,  _______,  KC_BSPC,  KC_DEL,   _______,  _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_PDOT,  XXXXXXX,  _______, },
                {   KC_LCTL,  KC_RALT,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SPC,   XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  KC_NO,    _______, }, },
               /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    [_FN]   = { {   KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______, },
                {   KC_TAB,   KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  KC_WH_L,  _______,  KC_F17,   KC_F21,  KC_PSCR,  S_4,      S_9,      S_0,      S_GR,    },
                {   KC_ESC,   KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  KC_WH_R,  _______,  KC_F16,   KC_F20,   KC_INS,   KC_PGUP,  KC_PGDN,  XXXXXXX,  _______, },
                {   KC_LSFT,  XXXXXXX,  KC_PWR,   KC_F15,   KC_SLEP,  KC_WAKE,  _______,  KC_NUM,   KC_CAPS,  KC_DEL,   KC_HOME,  KC_END,   XXXXXXX,  _______, },
                {   KC_LCTL,  KC_RALT,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SPC,   XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  KC_NO,    _______, }, },
               /*----------------------------------------------------------------------------------------------------------------------------------------------*/
};
