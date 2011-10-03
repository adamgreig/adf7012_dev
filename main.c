/*
 * Communicate with an ADF7012 radio
 * Copyright Adam Greig 2011.
 * Released under the GNU GPL v3. Insert GPL boilerplate here.
 */

#include "ch.h"
#include "hal.h"
#include "adf7012.h"

/*
 * LED control server.
 */
static WORKING_AREA(waLEDS, 128);
static msg_t LEDS(void * arg) {
    Mailbox* mbox = (Mailbox *)arg;
    msg_t msg, result;

    while(TRUE) {
        result = chMBFetch(mbox, &msg, TIME_INFINITE);
        if(result == RDY_OK) {
            if(msg & 1) {
                palSetPad(IOPORT1, PA_LED);
                palSetPad(IOPORT2, PB_TX_DATA);
            } else {
                palClearPad(IOPORT1, PA_LED);
                palClearPad(IOPORT2, PB_TX_DATA);
            }
        }
    }

    return 0;
}

/*
 * LED request client.
 */
static WORKING_AREA(waLEDC, 128);
static msg_t LEDC(void * arg) {
    Mailbox* mbox = (Mailbox *)arg;

    while(TRUE) {
        chMBPost(mbox, 0, TIME_INFINITE);
        chThdSleepMilliseconds(800);
        chMBPost(mbox, 1, TIME_INFINITE);
        chThdSleepMilliseconds(800);
    }

    return 0;
}

/*
 * Reset the radio, leaving all the pins in a defined state.
 */
void adf_reset() {
    palClearPad(IOPORT1, PA_CE);
    palSetPad(IOPORT1, PA_LE);
    palSetPad(IOPORT1, PA_CLK);
    palSetPad(IOPORT1, PA_DATA);
    palSetPad(IOPORT2, PB_TX_DATA);
    chThdSleepMilliseconds(100);
    palSetPad(IOPORT1, PA_CE);
    chThdSleepMilliseconds(100);
}

/*
 * Write out 32 bits to the ADF7012.
 */
void adf_write_reg(uint32_t data) {
    palClearPad(IOPORT1, PA_LE);
    chThdSleepMilliseconds(1);
    short int i;
    for(i=31; i>=0; i--) {
        palWritePad(IOPORT1, PA_DATA, (data & (1<<i))>>i);
        chThdSleepMilliseconds(1);
        palSetPad(IOPORT1, PA_CLK);
        chThdSleepMilliseconds(1);
        palClearPad(IOPORT1, PA_CLK);
        chThdSleepMilliseconds(1);
    }
    chThdSleepMilliseconds(1);
    palSetPad(IOPORT1, PA_LE);
    chThdSleepMilliseconds(1);
}

/*
 * Write the initial registers to set the radio up.
 */
void adf_setup() {

    // Register 0
    adf_write_reg(
        (0<<C1) | (0<<C2) |
        (0<<R0_R1) | (1<<R0_R2) | (0<<R0_R3) | (0<<R0_R4) |
        (1<<R0_CL1) | (1<<R0_CL2) | (1<<R0_CL3) | (1<<R0_CL4)
    );

    // Register 1
    adf_write_reg(
        (1<<C1) | (0<<C2) |
        (1<<R1_M1) | (1<<R1_M3) | (1<<R1_M4) | (1<<R1_M7) | (1<<R1_M8) |
        (1<<R1_M11) | (1<<R1_M12) |
        (1<<R1_N5) | (1<<R1_N6) | (1<<R1_N8)
    );

    // Register 2
    adf_write_reg(
        (0<<C1) | (1<<C2) |
        (1<<R2_P1) | (1<<R2_P2) | (1<<R2_P3) | (1<<R2_P4) | (1<<R2_P5) |
        (1<<R2_D1)
    );

    // Register 3
    adf_write_reg(
        (1<<C1) | (1<<C2) |
        (1<<R3_PD1) | (0<<R3_PD2) | (1<<R3_PD3) |
        (1<<R3_CP2) |
        (0<<R3_M1) | (0<<R3_M2) | (1<<R3_M3) | (0<<R3_M4) |
        (1<<R3_LD1) |
        (1<<R3_VB1) | (0<<R3_VB2) | (1<<R3_VB3) | (0<<R3_VB4) |
        (0<<R3_PA1) | (0<<R3_PA2) | (1<<R3_PA3)
    );

    chThdSleepMilliseconds(5);
    
    // Register 3, PA on
    adf_write_reg(
        (1<<C1) | (1<<C2) |
        (1<<R3_PD1) | (1<<R3_PD2) | (1<<R3_PD3) |
        (1<<R3_CP2) |
        (0<<R3_M1) | (0<<R3_M2) | (1<<R3_M3) | (0<<R3_M4) |
        (1<<R3_LD1) |
        (1<<R3_VB1) | (0<<R3_VB2) | (1<<R3_VB3) | (0<<R3_VB4) |
        (0<<R3_PA1) | (0<<R3_PA2) | (1<<R3_PA3)
    );
}

/*
 * Application entry point.
 */
int main(void) {

    /*
     * System initializations.
     * - HAL initialization, this also initializes the configured device drivers
     *   and performs the board-specific initializations.
     * - Kernel initialization, the main() function becomes a thread and the
     *   RTOS is active.
     */
    halInit();
    chSysInit();

    /*
     * Reset the radio
     */
    adf_reset();

    /*
     * Set up the radio
     */
    adf_setup();

    /*
     * Create a mailbox for IPC.
     */
    Mailbox mbox;
    msg_t mbox_buffer[3];
    chMBInit(&mbox, mbox_buffer, 3);

    /*
     * Create the LED server and client threads
     */
    chThdCreateStatic(waLEDS, sizeof(waLEDS), NORMALPRIO, LEDS, (void *)&mbox);
    chThdCreateStatic(waLEDC, sizeof(waLEDC), NORMALPRIO, LEDC, (void *)&mbox);

    /*
     * Normal main() thread activity, in this demo it does nothing
     */
    while (TRUE) {
        chThdSleepMilliseconds(500);
    }

    return 0;
}
