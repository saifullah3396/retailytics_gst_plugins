/**
 * Copyright (c) 2017-2020, NVIDIA CORPORATION.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __DSRETAILYTICS_LIB__
#define __DSRETAILYTICS_LIB__

#define MAX_LABEL_SIZE 128
#ifdef __cplusplus
extern "C" {
#endif

typedef struct DsRetailyticsCtx DsRetailyticsCtx;

// Init parameters structure as input, required for instantiating dsretailytics_lib
typedef struct
{
  // Width at which frame/object will be scaled
  int processingWidth;
  // height at which frame/object will be scaled
  int processingHeight;
  // Flag to indicate whether operating on crops of full frame
  int fullFrame;
} DsRetailyticsInitParams;

// Detected/Labelled object structure, stores bounding box info along with label
typedef struct
{
  float left;
  float top;
  float width;
  float height;
  char label[MAX_LABEL_SIZE];
} DsRetailyticsObject;

// Output data returned after processing
typedef struct
{
  int numObjects;
  DsRetailyticsObject object[4];
} DsRetailyticsOutput;

// Initialize library context
DsRetailyticsCtx * DsRetailyticsCtxInit (DsRetailyticsInitParams *init_params);

// Dequeue processed output
DsRetailyticsOutput *DsRetailyticsProcess (DsRetailyticsCtx *ctx, unsigned char *data);

// Deinitialize library context
void DsRetailyticsCtxDeinit (DsRetailyticsCtx *ctx);

#ifdef __cplusplus
}
#endif

#endif
