#include "keymap_common.h"

/*
 * As defined in "Le manuel technique du MO5" by Michel Oury,
 * published by TO TEK International, page 32, figure 21
 *
 *       A0:    A1:    A2:    A3:    A4:    A5:    A6:    A7:
 * B0: SHIFT   BASIC
 * B1:   W      ↑      C      RAZ    ENT    CNT    ACC    STOP
 * B2:   X      ←      V      Q      *      A      +      1
 * B3:   SP     ↓      B      S      /      Z      -      2
 * B4:   @      →      M      D      P      E      0      3
 * B5:   .      ⟲      L      F      O      R      9      4
 * B6:   ,      INS    K      G      I      T      8      5
 * B7:   N      EFF    J      H      U      Y      7      6
 *
 * Which would correspond to:
 *
 *  KEYMAP(
 *     LSFT,   LALT,                                             \
 *     W,       UP,    C,     CLR,   ENT,   LCTL,  RALT,  ESC,   \
 *     X,      LEFT,   V,     Q,     PAST,  A,     EQL,   1,     \
 *     SPC,    DOWN,   B,     S,     SLSH,  Z,     MINS,  2,     \
 *     COMM,   RIGHT,  M,     D,     P,     E,     0,     3,     \
 *     DOT,    HOME,   L,     F,     O,     R,     9,     4,     \
 *     COMM,   INS,    K,     G,     I,     T,     8,     5,     \
 *     N,      BSPC,   J,     H,     U,     Y,     7,     6)
 *
 * But we want the keyboard, setup with a French keymap, to more
 * or less match what's on the keyboard, and avoid duplicate or
 * unusable keys.
 */

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(
       LSFT,   LALT,                                             \
       Z,      UP,     C,     LGUI,  ENT,   LCTL,  RALT,  ESC,   \
       X,      LEFT,   V,     A,     PAST,  Q,     EQL,   1,     \
       SPC,    DOWN,   B,     S,     SLSH,  W,     MINS,  2,     \
       COMM,   RIGHT,  SCLN,  D,     P,     E,     0,     3,     \
       DOT,    TAB,    L,     F,     O,     R,     9,     4,     \
       M,      INS,    K,     G,     I,     T,     8,     5,     \
       N,      BSPC,   J,     H,     U,     Y,     7,     6),
};

const action_t PROGMEM fn_actions[] = {
};

uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
#if defined(__AVR__)
    return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
#else
    return keymaps[(layer)][(key.row)][(key.col)];
#endif
}

action_t keymap_fn_to_action(uint8_t keycode)
{
#if defined(__AVR__)
    return (action_t)pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
#else
    return fn_actions[FN_INDEX(keycode)];
#endif
}
