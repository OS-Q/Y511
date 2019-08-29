/**
 * @section License
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016-2017, Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This file is part of the Pumbaa project.
 */

#ifndef __MODULE_DRIVERS_CLASS_EXTI_H__
#define __MODULE_DRIVERS_CLASS_EXTI_H__

#include "pumbaa.h"

#if CONFIG_PUMBAA_CLASS_EXTI == 1

enum class_exti_chan_type_t {
    class_exti_chan_type_none_t = 0,
    class_exti_chan_type_event_t,
    class_exti_chan_type_queue_t
};

struct class_exti_t {
    mp_obj_base_t base;
    struct exti_driver_t exti;
    enum class_exti_chan_type_t chan_type;
    union {
        struct {
            struct class_event_t *obj_p;
            uint32_t mask;
        } event;
        struct {
            struct class_queue_t *obj_p;
            mp_obj_t str_obj;
            char *buf_p;
            size_t size;
        } queue;
    } chan;
    mp_obj_t callback;
};

extern const mp_obj_type_t module_drivers_class_exti;

#endif

#endif