/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "keymap_german_mac_iso.h"

enum layers{
  MAC_BASE,
  NEO3,
  NEO4,
  MAC_FN,
  WIN_BASE,
  WIN_FN,
};

#define NEO2_UE                      RALT(DE_Y)
#define NEO2_OE                      RALT(DE_P)
#define NEO2_AE                      RALT(DE_Q)

#define NEO2_NOP                     KC_TRANSPARENT
#define NEO2_TIL                     KC_TILD

#define NEO2_LMOD3                   MO(NEO3)
#define NEO2_RMOD3                   NEO2_LMOD3

#define NEO2_LMOD4                   MO(NEO4)
#define NEO2_RMOD4                   NEO2_LMOD4

// Definitions copied and modified from https://github.com/yeldiRium/qmk-neo2
// NEO_3 special characters
#define NEO2_L3_CAPITAL_SS           RSA(DE_S)                   // ẞ
#define NEO2_L3_CAPITAL_UE           S(DE_UDIA)                  // Ü
#define NEO2_L3_CAPITAL_OE           S(DE_ODIA)                  // Ö
#define NEO2_L3_CAPITAL_AE           S(DE_ADIA)                  // Ä
#define NEO2_L3_SUPERSCRIPT_1        RALT(DE_1)                  // ¹
#define NEO2_L3_SUPERSCRIPT_2        DE_SUP2                     // ²
#define NEO2_L3_SUPERSCRIPT_3        DE_SUP3                     // ³
#define NEO2_L3_RSAQUO               RSA(DE_Y)                   // ›
#define NEO2_L3_LSAQUO               RSA(DE_X)                   // ‹
#define NEO2_L3_RAQUO                RALT(DE_Y)                  // »
#define NEO2_L3_LAQUO                RALT(DE_X)                  // «
#define NEO2_L3_CENT                 RALT(DE_C)                  // ¢
#define NEO2_L3_YEN                  RSA(DE_Z)                   // ¥
#define NEO2_L3_SBQUO                RSA(DE_V)                   // ‚
#define NEO2_L3_LEFT_SINGLE_QUOTE    RSA(DE_B)                   // ‘
#define NEO2_L3_RIGHT_SINGLE_QUOTE   RSA(DE_N)                   // ’
#define NEO2_L3_LOW9_DBQUOTE         RALT(DE_V)                  // „
#define NEO2_L3_LEFT_DBQUOTE         RALT(DE_B)                  // “
#define NEO2_L3_RIGHT_DBQUOTE        RALT(DE_N)                  // ”
#define NEO2_L3_ELLIPSIS             RALT(DE_DOT)                // …
#define NEO2_L3_UNDERSCORE           DE_UNDS                     // _
#define NEO2_L3_LBRACKET             RALT(KC_5)                  // [
#define NEO2_L3_RBRACKET             RALT(KC_6)                  // ]
#define NEO2_L3_CIRCUMFLEX           DE_CIRC                     // ^
#define NEO2_L3_EXCLAMATION          DE_EXLM                     // !
#define NEO2_L3_LESSTHAN             KC_GRV                      // <
#define NEO2_L3_GREATERTHAN          S(KC_GRV)                   // >
//#define NEO2_L3_LESSTHAN             DE_LABK                     // <
//#define NEO2_L3_GREATERTHAN          DE_RABK                     // >
#define NEO2_L3_EQUAL                DE_EQL                      // =
#define NEO2_L3_AMPERSAND            DE_AMPR                     // &
#define NEO2_L3_SMALL_LONG_S         RALT(DE_S)                  // ſ
#define NEO2_L3_BSLASH               DE_BSLS                     // (backslash)
#define NEO2_L3_SLASH                DE_SLSH                     // /
#define NEO2_L3_CLBRACKET            RALT(KC_8)                  // {
#define NEO2_L3_CRBRACKET            RALT(KC_9)                  // }
#define NEO2_L3_ASTERISK             DE_ASTR                     // *
#define NEO2_L3_QUESTIONMARK         DE_QUES                     // ?
#define NEO2_L3_LPARENTHESES         DE_LPRN                     // (
#define NEO2_L3_RPARENTHESES         DE_RPRN                     // )
#define NEO2_L3_HYPHEN_MINUS         DE_MINS                     // -
#define NEO2_L3_COLON                DE_COLN                     // :
#define NEO2_L3_AT                   RALT(DE_L)                     // @
#define NEO2_L3_HASH                 DE_HASH                     // #
#define NEO2_L3_PIPE                 RALT(KC_7)                  // |
#define NEO2_L3_TILDE                RALT(DE_N)                  // ~
#define NEO2_L3_BACKTICK             DE_GRV                      // `
#define NEO2_L3_PLUS                 DE_PLUS                     // +
#define NEO2_L3_PERCENT              DE_PERC                     // %
#define NEO2_L3_DOUBLE_QUOTE         DE_DQUO                     // "
#define NEO2_L3_SINGLE_QUOTE         DE_QUOT                     // '
#define NEO2_L3_SEMICOLON            DE_SCLN                     // ;

// NEO_4 special characters
#define NEO2_L3_FEMININE_ORDINAL     RSA(DE_F)                   // ª
#define NEO2_L3_MASCULINE_ORDINAL    RSA(DE_M)                   // º
#define NEO2_L3_NUMERO_SIGN          KC_NO                       // №
#define NEO2_L3_MIDDLE_DOT           RALT(DE_COMM)               // ·
#define NEO2_L3_BRITISH_POUND        RSA(DE_3)                   // £
#define NEO2_L3_CURRENCY_SIGN        RSA(DE_4)                   // ¤
#define NEO2_L3_INV_EXCLAMATION      RSA(DE_1)                   // ¡
#define NEO2_L3_INV_QUESTIONMARK     RSA(DE_SS)                  // ¿
#define NEO2_L3_DOLLAR               DE_DLR                      // $
#define NEO2_L3_EN_DASH              RALT(DE_MINS)               // –
#define NEO2_L3_EM_DASH              RSA(DE_MINS)                // —


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_iso(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     DE_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   DE_X,     DE_V,     DE_L,     DE_C,     DE_W,     DE_K,     DE_H,     DE_G,     DE_F,     DE_Q,     DE_SS,  _______,            KC_DEL,   KC_END,   KC_PGDN,
        NEO2_LMOD3, DE_U,   DE_I,     DE_A,     DE_E,     DE_O,     DE_S,     DE_N,     DE_R,     DE_T,     DE_D,     DE_Y,     NEO2_RMOD3,  KC_ENT,
        KC_LSFT,NEO2_LMOD4, DE_UDIA,  DE_ODIA,  DE_ADIA,  DE_P,     DE_Z,     DE_B,     DE_M,     KC_COMM,  KC_DOT,   DE_J,               KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),
    
    
    [NEO3] = LAYOUT_tkl_iso(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_SIRI,  RGB_MOD,
        NEO2_NOP, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        NEO2_NOP, NEO2_L3_ELLIPSIS, NEO2_L3_UNDERSCORE, NEO2_L3_LBRACKET,  NEO2_L3_RBRACKET,  NEO2_L3_CIRCUMFLEX, NEO2_L3_EXCLAMATION,  NEO2_L3_LESSTHAN,     NEO2_L3_GREATERTHAN, NEO2_L3_EQUAL, NEO2_L3_AMPERSAND,          _______,            _______,            KC_DEL,   KC_END,   KC_PGDN,
        NEO2_NOP, NEO2_L3_BSLASH,   NEO2_L3_SLASH,      NEO2_L3_CLBRACKET, NEO2_L3_CRBRACKET, NEO2_L3_ASTERISK,   NEO2_L3_QUESTIONMARK, NEO2_L3_LPARENTHESES, NEO2_L3_RPARENTHESES,  NEO2_L3_HYPHEN_MINUS,       NEO2_L3_COLON,     NEO2_L3_AT,   KC_TRNS,  KC_ENT,
        NEO2_NOP, KC_TRNS,          NEO2_L3_HASH,       NEO2_L3_DOLLAR,    NEO2_L3_PIPE,      NEO2_L3_TILDE,      NEO2_L3_BACKTICK, NEO2_L3_PLUS,  NEO2_L3_PERCENT,      NEO2_L3_DOUBLE_QUOTE,  NEO2_L3_SINGLE_QUOTE,       NEO2_L3_SEMICOLON, KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),
    
    
    [NEO4] = LAYOUT_tkl_iso(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_SIRI,  RGB_MOD,
        NEO2_NOP, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     DE_ASTR,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        NEO2_NOP, KC_PGUP,  KC_BSPC,  KC_UP,    KC_DELETE,KC_PGDN,  NEO2_L3_INV_EXCLAMATION, KC_7, KC_8, KC_9, DE_PLUS, NEO2_L3_EM_DASH,  KC_RBRC, KC_DEL,   KC_END,   KC_PGDN,
        NEO2_NOP, KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,   NEO2_L3_INV_QUESTIONMARK,KC_4, KC_5, KC_6, DE_COMM, KC_DOT, NEO2_NOP,  KC_ENT,
        NEO2_NOP, KC_TRNS,  KC_ESCAPE,KC_TAB,   KC_INSERT,KC_ENTER, _______,NEO2_L3_COLON,   KC_1, KC_2, KC_3, NEO2_L3_SEMICOLON,KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_iso(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_iso(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_CTANA, RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_iso(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______)
};

void keyboard_post_init_user(void) {
    // Custom startup RGB effect
    rgblight_mode(RGB_MATRIX_SOLID_COLOR); // Set the default mode
    rgblight_sethsv(HSV_GREEN); // Set the initial color (Hue, Saturation, Value)
}
