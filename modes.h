/* avr-lighthouse
 * Lighthouse controller.
 *
 * (c) Karl-Martin Skontorp <kms@skontorp.net> ~ http://picofarad.org/
 * Licensed under the GNU GPL 2.0 or later.
 */

#ifndef _MODES_H
#define _MODES_H 1

#include <stdint.h>

/* Lights */
#define L_D 0x00 /* Dark */
#define L_W 0x01 /* Primary White */
#define L_W2 0x02 /* 2nd White */
#define L_W3 0x04 /* 3rd White */
#define L_W4 0x08 /* 4th White */
#define L_R 0x10 /* Red */
#define L_G 0x20 /* Green */
#define L_H 0x40 /* Fog horn */

/* One single "symbol" */
typedef struct {
    uint8_t lightPattern;
    uint16_t duration;
} symbol;

/* A seqeunce of symbols */
typedef struct {
    uint8_t length;
    symbol *symbols;
} mode;

/* All available light modes */
extern mode modes[];

#endif
