/* avr-lighthouse
 * Lighthouse controller.
 *
 * (c) Karl-Martin Skontorp <kms@skontorp.net> ~ http://picofarad.org/
 * Licensed under the GNU GPL 2.0 or later.
 */

#define F_CPU 1e6

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include "modes.h"

volatile mode m;

ISR(SIG_OUTPUT_COMPARE1A) {
    static uint16_t i = 0;
    static uint8_t s = 0;
    
    PORTC = ~(m.symbols[s % m.length].lightPattern);

    /* Advance timer and move to next symbol if timer has expired. */
    if (i++ >= m.symbols[s % m.length].duration) {
        s++;
        i = 0;
    }

    wdt_reset();
}

int main(void) {
    /* Watchdog */
    wdt_reset();
    wdt_enable(WDTO_15MS);

    /* Ports */
    PORTB = 0xff;
    PORTC = 0xff;
    PORTD = 0xff;
    DDRC |= _BV(DDC0);

    /* Power saving */

    power_all_disable();
    power_timer1_enable();
    ACSR = _BV(ACD);
    DIDR0 = _BV(ADC5D) | _BV(ADC4D) | _BV(ADC3D) | _BV(ADC2D) | 
        _BV(ADC1D) | _BV(ADC0D);
    DIDR1 = _BV(AIN1D) | _BV(AIN0D);

    set_sleep_mode(SLEEP_MODE_IDLE);
    
    /* Timer */

    TCCR1B = _BV(WGM12) | _BV(CS10);
    TIMSK1 = _BV(OCIE1A);
    OCR1A = 499;

    /* Select light mode */
    m = modes[PORTB];
    m = modes[4];

    /* Start it up */
    sei();

    for (;;) {
        sleep_mode();
    }
}
