#include "iris.h"
#include "keymap_swedish.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NAVIGATION 3
#define _CONFIG 4
#define _EMPTY 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NAVIGATION,
  CONFIG
};

#define KC_ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_CNFG CONFIG
#define KC_NAV NAVIGATION
#define KC_RST RESET

#define KC_MT_TB LT(_NAVIGATION, KC_TAB)
#define KC_OSL1 OSL(_CONFIG)

#define KC_AA SE_ARNG
#define KC_AE SE_ADIA
#define KC_OE SE_ODIA

#define MC_BSLS S(A(KC_7))
#define MC_PIPE A(KC_7)

#define MC_LCBR S(A(KC_8))
#define MC_RCBR S(A(KC_9))

#define MC_STAR S(KC_BSLS)

#define N_HL C(A(KC_LEFT))
#define N_HR C(A(KC_RIGHT))
#define N_HT C(A(KC_UP))
#define N_HB C(A(KC_DOWN))

#define N_QTL C(A(KC_U))
#define N_QTR C(A(KC_I))
#define N_QBR C(A(KC_K))
#define N_QBL C(A(KC_J))

#define N_TL C(A(KC_D))
#define N_TL2 C(A(KC_E))
#define N_TC C(A(KC_F))
#define N_TR2 C(A(KC_T))
#define N_TR C(A(KC_G))

#define N_SM C(A(S(KC_ENTER)))
#define N_SVM C(A(S(KC_UP)))
#define N_SR C(A(S(KC_BSPC)))

#define N_SL C(A(KC_PLUS))
#define N_SS C(A(KC_SLSH))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   MT_TB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , AA ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  , OE , AE ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  , BSPC,   DEL , N  , M  , COMM,DOT ,SLSH,MINS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        LGUI,RASE,SPC,         ENT,LOWR,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     SE_TILD,KC_EXLM,SE_AT  ,KC_HASH,SE_DLR ,KC_PERC,                     SE_CIRC,SE_AMPR,SE_ASTR,SE_SLSH,SE_LPRN,SE_RPRN,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     SE_ACUT,_______,_______,_______,_______,_______,                     _______,_______,_______,MC_PIPE,MC_LCBR,MC_RCBR,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,MC_BSLS,SE_LBRC,SE_RBRC,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,_______,     _______,_______,_______,_______,MC_STAR,KC_NUBS,SE_RABK,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                   _______,KC_OSL1,_______,         _______,_______,_______
  //                              `-------+-------+-------'        `-------+-------+-------'
),

  [_RAISE] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                     KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     SE_GRV ,KC_HOME, KC_UP ,KC_PGUP,_______,_______,                     _______,KC_BTN1,KC_MS_U,KC_BTN2,_______,KC_VOLU,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,                     _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,KC_VOLD,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     _______,KC_END ,_______,KC_PGDN,_______,_______,_______,     _______,_______,_______,_______,KC_MPRV,KC_MNXT,KC_MPLY,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                   _______,_______,_______,         _______,KC_OSL1,_______
  //                              `-------+-------+-------'        `-------+-------+-------'
  ),

  [_NAVIGATION] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______, N_TL2 , N_QTL , N_HT  , N_QTR , N_TR2 ,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______, N_TL  , N_HL  , N_TC  , N_HR  , N_TR  ,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     _______,_______, N_QBL , N_HB  , N_QBR ,_______,_______,     _______,_______,_______,_______,_______, N_SS  , N_SL  ,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                    _______,_______, N_SM  ,        N_SR  ,_______,_______
  //                              `-------+-------+-------'        `-------+-------+-------'
  ),

  [_CONFIG] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______, RESET ,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     _______,_______ ,_______,_______,_______,_______,KC_SLEP,    _______,_______,_______,_______,_______,_______,_______,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                    AG_NORM,_______,KC_WAKE,       _______,_______,AG_SWAP
  //                              `-------+-------+-------'        `-------+-------+-------'
),
  [_EMPTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,_______,     _______,_______,_______,_______,_______,_______,_______,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
                                   _______,_______,_______,         _______,_______,_______
  //                              `-------+-------+-------'        `-------+-------+-------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      }
      return false;
      break;
      case CONFIG:
        if (record->event.pressed) {
          layer_on(_CONFIG);
          update_tri_layer(_LOWER, _RAISE, _CONFIG);
        } else {
          layer_off(_CONFIG);
          update_tri_layer(_LOWER, _RAISE, _CONFIG);
        }
        return false;
        break;
  }
  return true;
}
