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

#ifndef __DSWORLDCOORDSANALYTICS_LIB__
#define __DSWORLDCOORDSANALYTICS_LIB__

#define MAX_LABEL_SIZE 128
#ifdef __cplusplus
extern "C" {
#endif

typedef struct DsWorldCoordsAnalyticsCtx DsWorldCoordsAnalyticsCtx;

/** Maximum batch size to be supported by dsretailytics. */
#define MAX_CLASS_IDS_PER_ANALYTICS G_MAXINT

// Init parameters structure as input, required for instantiating dsworld_coords_analyticslib
typedef struct
{
  // Class ids to this analytics operation on
  gint class_ids[MAX_CLASS_IDS_PER_ANALYTICS];

  // Number of class ids attached to this analytics object
  gint num_classes;
} DsWorldCoordsAnalyticsInitParams;

// Stores output world coordinates of the object after transformation
typedef struct
{
  float world_coords_x;
  float world_coords_y;
} DsWorldCoordsAnalyticsObject;

// Initialize library context
DsWorldCoordsAnalyticsCtx * DsWorldCoordsAnalyticsCtxInit (DsWorldCoordsAnalyticsInitParams *init_params);

// Dequeue processed output
void *DsWorldCoordsAnalyticsProcess (DsWorldCoordsAnalyticsCtx *ctx, NvDsBatchMeta *batch_meta);

// Deinitialize library context
void DsWorldCoordsAnalyticsCtxDeinit (DsWorldCoordsAnalyticsCtx *ctx);

#ifdef __cplusplus
}
#endif

#endif
