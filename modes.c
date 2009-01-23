/* avr-lighthouse
 * Lighthouse controller.
 *
 * (c) Karl-Martin Skontorp <kms@skontorp.net> ~ http://picofarad.org/
 * Licensed under the GNU GPL 2.0 or later.
 */

#include "modes.h"

/* ** Dark ** */
symbol d[] = {
    {L_D, 1},
};

/* ** F - Fixed white ** */
symbol f[] = {
    {L_W, 1},
};

/* ** Oc - Occulting ** */
/* Oc.W.12s */
symbol oc_w_12s[] = {
    {L_W, 10000},
    {L_D, 2000},
};

/* Oc(2)W.13s */
symbol oc_2_w_13s[] = {
    {L_W, 10000},
    {L_D, 1000},
    {L_W, 1000},
    {L_D, 1000},
};

/* Oc(2+1)W.12s */
symbol oc_2_1_w_12s[] = {
    {L_W, 4000},
    {L_D, 1000},
    {L_W, 1000},
    {L_D, 1000},
    {L_W, 4000},
    {L_D, 1000},
};

/* ** Iso - Isophase ** */
/* Iso. W. 10s */
symbol iso_w_10s[] = {
    {L_W, 5000},
    {L_D, 5000},
};

/* ** Fl - Flashing ** */
/* Fl.W.10s */
symbol fl_w_10s[] = {
    {L_W, 1500},
    {L_D, 8500},
};

/* LFl.W.10s */
symbol lfl_w_10s[] = {
    {L_W, 3000},
    {L_D, 7000},
};

/* Fl(3)W.15s */
symbol fl_3_w_15s[] = {
    {L_W, 1000},
    {L_D, 1000},
    {L_W, 1000},
    {L_D, 1000},
    {L_W, 1000},
    {L_D, 10000},
};

/* Fl(2+1)W.17s */
symbol fl_2_1_w_17s[] = {
    {L_W, 1000},
    {L_D, 2000},
    {L_W, 1000},
    {L_D, 6000},
    {L_W, 1000},
    {L_D, 6000},
};

/* ** Ultra Quick ** */
/* UQ.W */
symbol uq_w[] = {
    {L_W, 188},
    {L_D, 188},
};

/* IUQ.W.12s */
symbol uiq_w_12s[] = {
    {L_W, 417},
    {L_D, 417},
    {L_W, 417},
    {L_D, 417},
    {L_W, 417},
    {L_D, 417},
    {L_W, 417},
    {L_D, 417},
    {L_W, 417},
    {L_D, 417},
    {L_W, 417},
    {L_D, 7000},
};

/* ** Morse code ** */
/* Mo(K)W.10s */
symbol mo_k_w_10s[] = {
    {L_W, 1300},
    {L_D, 500},
    {L_W, 400},
    {L_D, 500},
    {L_W, 1300},
    {L_D, 6000},
};

/* ** Fixed and flashing ** */
/* FFl.W.5s (by crude Pulse-Width Modulation) */
symbol ffl_w_5s[] = {
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 1000},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
    {L_D, 100},
    {L_W, 10},
};

mode modes[]  =  {
    /*  0 */ {1, d},
    /*  1 */ {1, f},
    /*  2 */ {2, oc_w_12s },
    /*  3 */ {5, oc_2_w_13s},
    /*  4 */ {6, oc_2_1_w_12s},
    /*  5 */ {2, iso_w_10s},
    /*  6 */ {2, fl_w_10s},
    /*  7 */ {2, lfl_w_10s},
    /*  8 */ {6, fl_3_w_15s},
    /*  9 */ {6, fl_2_1_w_17s},
    /* 10 */ {2, uq_w},
    /* 11 */ {12, uiq_w_12s},
    /* 12 */ {6, mo_k_w_10s},
    /* 13 */ {53, ffl_w_5s},
};
