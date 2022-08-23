// Auto-generated file. Do not edit!
//   Template: src/u32-filterbank-accumulate/neon.c.in
//   Generator: tools/xngen
//
// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <arm_neon.h>

#include <xnnpack/math.h>
#include <xnnpack/filterbank.h>


void xnn_u32_filterbank_accumulate_ukernel__neon_x2(
    size_t rows,
    const uint32_t* input,
    const uint8_t* weight_widths,
    const uint16_t* weights,
    uint64_t* output) {

  assert(rows != 0);
  assert(input != NULL);
  assert(weight_widths != NULL);
  assert(weights != NULL);
  assert(output != NULL);

  uint64x2_t weight_accumulator = vdupq_n_u64(0);

  do {
    size_t n = (size_t) *weight_widths++;
    assert(n != 0);

    for (;n >= 2; n -= 2) {
      const uint32x2_t vi = vld1_u32(input); input += 2;
      const uint16x4_t vw = vld1_u16(weights); weights += 4;
      const uint32x4_t vw32 = vmovl_u16(vw);

      weight_accumulator = vmlal_lane_u32(weight_accumulator, vget_low_u32(vw32), vi, 0);
      weight_accumulator = vmlal_lane_u32(weight_accumulator, vget_high_u32(vw32), vi, 1);
    }
    if (n != 0) {
      do {
        const uint32x2_t vi = vld1_dup_u32(input); input += 1;
        const uint16x4_t vw = vreinterpret_u16_u32(vld1_dup_u32((const void*) weights)); weights += 2;
        const uint32x2_t vw32 = vget_low_u32(vmovl_u16(vw));

        weight_accumulator = vmlal_u32(weight_accumulator, vw32, vi);
      } while (--n != 0);
    }

    vst1_u64(output, vget_low_u64(weight_accumulator));  output += 1;
    weight_accumulator = vcombine_u64(vget_high_u64(weight_accumulator), vget_high_u64(weight_accumulator));

  } while (--rows != 0);
}
