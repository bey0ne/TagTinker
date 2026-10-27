/*
 * IR transmitter API.
 *
 * Sends already-built ESL frames over the built-in IR LED.
 * Frames are played by TIM1 + DMA; tagtinker_ir_transmit() blocks the calling
 * thread (sleeping, not spinning) until the last repeat has been sent.
 */

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void tagtinker_ir_init(void);

void tagtinker_ir_deinit(void);

/* Repeats are sent with PP4 timing; the high bit is ignored for legacy saved data.
 * len must be 1..TAGTINKER_IR_MAX_FRAME_LEN (96). delay is the gap between
 * repeats in 500 us units. Returns false if stopped, invalid or not init. */
bool tagtinker_ir_transmit(const uint8_t* data, size_t len, uint16_t repeats, uint8_t delay);

bool tagtinker_ir_is_busy(void);

void tagtinker_ir_stop(void);
