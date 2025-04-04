// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-rdsum/neon.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/reduce.h"
#include "src/xnnpack/math.h"


void xnn_f32_rdsum_ukernel_7p7x__neon_c16(
    size_t rows,
    size_t channels,
    const float* input,
    size_t input_stride,
    const float* zero,
    float* output,
    const struct xnn_f32_scale_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(rows != 0);
  assert(channels != 0);
  assert(input != NULL);
  assert(output != NULL);

  const float32x4_t vscale = vdupq_n_f32(params->scalar.scale);

  size_t input_increment = 7 * input_stride;
  for (; channels >= 16; channels -= 16) {
    const float* i0 = input;
    const float* i1 = (const float*) ((uintptr_t) input + 1 * input_stride);
    const float* i2 = (const float*) ((uintptr_t) input + 2 * input_stride);
    const float* i3 = (const float*) ((uintptr_t) input + 3 * input_stride);
    const float* i4 = (const float*) ((uintptr_t) input + 4 * input_stride);
    const float* i5 = (const float*) ((uintptr_t) input + 5 * input_stride);
    const float* i6 = (const float*) ((uintptr_t) input + 6 * input_stride);

    float32x4_t vacc0 = vdupq_n_f32(0.f);
    float32x4_t vacc1 = vdupq_n_f32(0.f);
    float32x4_t vacc2 = vdupq_n_f32(0.f);
    float32x4_t vacc3 = vdupq_n_f32(0.f);

    for (int r = rows; r > 0; r -= 7) {
      if XNN_UNPREDICTABLE(r < 2) {
        i1 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 2) {
        i2 = zero;
      }
      if XNN_UNPREDICTABLE(r < 4) {
        i3 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 4) {
        i4 = zero;
      }
      if XNN_UNPREDICTABLE(r < 6) {
        i5 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 6) {
        i6 = zero;
      }
      float32x4_t vin0;
      float32x4_t vin1;
      float32x4_t vin2;
      float32x4_t vin3;
      vin0 = vld1q_f32(&i0[0]);
      vin1 = vld1q_f32(&i0[4]);
      vin2 = vld1q_f32(&i0[8]);
      vin3 = vld1q_f32(&i0[12]);
      vacc0 = vaddq_f32(vin0, vacc0);
      vacc1 = vaddq_f32(vin1, vacc1);
      vacc2 = vaddq_f32(vin2, vacc2);
      vacc3 = vaddq_f32(vin3, vacc3);
      vin0 = vld1q_f32(&i1[0]);
      vin1 = vld1q_f32(&i1[4]);
      vin2 = vld1q_f32(&i1[8]);
      vin3 = vld1q_f32(&i1[12]);
      vacc0 = vaddq_f32(vin0, vacc0);
      vacc1 = vaddq_f32(vin1, vacc1);
      vacc2 = vaddq_f32(vin2, vacc2);
      vacc3 = vaddq_f32(vin3, vacc3);
      vin0 = vld1q_f32(&i2[0]);
      vin1 = vld1q_f32(&i2[4]);
      vin2 = vld1q_f32(&i2[8]);
      vin3 = vld1q_f32(&i2[12]);
      vacc0 = vaddq_f32(vin0, vacc0);
      vacc1 = vaddq_f32(vin1, vacc1);
      vacc2 = vaddq_f32(vin2, vacc2);
      vacc3 = vaddq_f32(vin3, vacc3);
      vin0 = vld1q_f32(&i3[0]);
      vin1 = vld1q_f32(&i3[4]);
      vin2 = vld1q_f32(&i3[8]);
      vin3 = vld1q_f32(&i3[12]);
      vacc0 = vaddq_f32(vin0, vacc0);
      vacc1 = vaddq_f32(vin1, vacc1);
      vacc2 = vaddq_f32(vin2, vacc2);
      vacc3 = vaddq_f32(vin3, vacc3);
      vin0 = vld1q_f32(&i4[0]);
      vin1 = vld1q_f32(&i4[4]);
      vin2 = vld1q_f32(&i4[8]);
      vin3 = vld1q_f32(&i4[12]);
      vacc0 = vaddq_f32(vin0, vacc0);
      vacc1 = vaddq_f32(vin1, vacc1);
      vacc2 = vaddq_f32(vin2, vacc2);
      vacc3 = vaddq_f32(vin3, vacc3);
      vin0 = vld1q_f32(&i5[0]);
      vin1 = vld1q_f32(&i5[4]);
      vin2 = vld1q_f32(&i5[8]);
      vin3 = vld1q_f32(&i5[12]);
      vacc0 = vaddq_f32(vin0, vacc0);
      vacc1 = vaddq_f32(vin1, vacc1);
      vacc2 = vaddq_f32(vin2, vacc2);
      vacc3 = vaddq_f32(vin3, vacc3);
      vin0 = vld1q_f32(&i6[0]);
      vin1 = vld1q_f32(&i6[4]);
      vin2 = vld1q_f32(&i6[8]);
      vin3 = vld1q_f32(&i6[12]);
      vacc0 = vaddq_f32(vin0, vacc0);
      vacc1 = vaddq_f32(vin1, vacc1);
      vacc2 = vaddq_f32(vin2, vacc2);
      vacc3 = vaddq_f32(vin3, vacc3);
      i0 = (const float*) ((uintptr_t) i0 + input_increment);
      i1 = (const float*) ((uintptr_t) i1 + input_increment);
      i2 = (const float*) ((uintptr_t) i2 + input_increment);
      i3 = (const float*) ((uintptr_t) i3 + input_increment);
      i4 = (const float*) ((uintptr_t) i4 + input_increment);
      i5 = (const float*) ((uintptr_t) i5 + input_increment);
      i6 = (const float*) ((uintptr_t) i6 + input_increment);
    }
    vacc0 = vmulq_f32(vacc0, vscale);
    vacc1 = vmulq_f32(vacc1, vscale);
    vacc2 = vmulq_f32(vacc2, vscale);
    vacc3 = vmulq_f32(vacc3, vscale);

    const float* o = output;
    float32x4_t vo0 = vld1q_f32(o); o += 4;
    float32x4_t vo1 = vld1q_f32(o); o += 4;
    float32x4_t vo2 = vld1q_f32(o); o += 4;
    float32x4_t vo3 = vld1q_f32(o); o += 4;
    vacc0 = vaddq_f32(vo0, vacc0);
    vacc1 = vaddq_f32(vo1, vacc1);
    vacc2 = vaddq_f32(vo2, vacc2);
    vacc3 = vaddq_f32(vo3, vacc3);
    vst1q_f32(output, vacc0); output += 4;
    vst1q_f32(output, vacc1); output += 4;
    vst1q_f32(output, vacc2); output += 4;
    vst1q_f32(output, vacc3); output += 4;

    input = (const float*) ((uintptr_t) input + 16 * sizeof(float));
  }
  if (channels != 0) {
    size_t input_increment = 7 * input_stride;
    const float* i0 = input;
    const float* i1 = (const float*) ((uintptr_t) input + 1 * input_stride);
    const float* i2 = (const float*) ((uintptr_t) input + 2 * input_stride);
    const float* i3 = (const float*) ((uintptr_t) input + 3 * input_stride);
    const float* i4 = (const float*) ((uintptr_t) input + 4 * input_stride);
    const float* i5 = (const float*) ((uintptr_t) input + 5 * input_stride);
    const float* i6 = (const float*) ((uintptr_t) input + 6 * input_stride);
    float32x4_t vacc[4];
    vacc[0] = vdupq_n_f32(0.f);
    vacc[1] = vdupq_n_f32(0.f);
    vacc[2] = vdupq_n_f32(0.f);
    vacc[3] = vdupq_n_f32(0.f);

    size_t num_chunks = round_up_po2(channels, 4) >> 2;
    for (int r = rows; r > 0; r -= 7) {
      if XNN_UNPREDICTABLE(r < 2) {
        i1 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 2) {
        i2 = zero;
      }
      if XNN_UNPREDICTABLE(r < 4) {
        i3 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 4) {
        i4 = zero;
      }
      if XNN_UNPREDICTABLE(r < 6) {
        i5 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 6) {
        i6 = zero;
      }
      for (int i = 0; i < num_chunks; ++i) {
        vacc[i] = vaddq_f32(vld1q_f32(&i0[i*4]), vacc[i]);
        vacc[i] = vaddq_f32(vld1q_f32(&i1[i*4]), vacc[i]);
        vacc[i] = vaddq_f32(vld1q_f32(&i2[i*4]), vacc[i]);
        vacc[i] = vaddq_f32(vld1q_f32(&i3[i*4]), vacc[i]);
        vacc[i] = vaddq_f32(vld1q_f32(&i4[i*4]), vacc[i]);
        vacc[i] = vaddq_f32(vld1q_f32(&i5[i*4]), vacc[i]);
        vacc[i] = vaddq_f32(vld1q_f32(&i6[i*4]), vacc[i]);
      }
      i0 = (const float*) ((uintptr_t) i0 + input_increment);
      i1 = (const float*) ((uintptr_t) i1 + input_increment);
      i2 = (const float*) ((uintptr_t) i2 + input_increment);
      i3 = (const float*) ((uintptr_t) i3 + input_increment);
      i4 = (const float*) ((uintptr_t) i4 + input_increment);
      i5 = (const float*) ((uintptr_t) i5 + input_increment);
      i6 = (const float*) ((uintptr_t) i6 + input_increment);
    }
    for (int i = 0; i < (channels + 4) >> 2; ++i) {
      vacc[i] = vmulq_f32(vacc[i], vscale);
    }

    float32x4_t vo[4];
    const float* o = output;
    for (int i = 0; i < channels >> 2; ++i) {
      vo[i] = vld1q_f32(o); o += 4;
    }
    for (int i = 0; i < channels >> 2; ++i) {
      vacc[i] = vaddq_f32(vo[i], vacc[i]);
    }
    for (int i = 0; i < channels >> 2; ++i) {
      vst1q_f32(output, vacc[i]); output += 4;
    }
    size_t pos = channels >> 2;
    channels &= 0x3;
    float32x2_t vacc_low = vget_low_f32(vacc[pos]);
    if (channels & 2) {
      vst1_f32(output, vadd_f32(vld1_f32(output), vacc_low)); output += 2;
      vacc_low = vget_high_f32(vacc[pos]);
    }
    if (channels & 1) {
      vst1_lane_f32(output, vadd_f32(vld1_dup_f32(output), vacc_low), 0);
    }
  }
}
