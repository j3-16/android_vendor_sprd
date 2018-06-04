/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/******************************************************************************
 **                   Edit    History                                         *
 **---------------------------------------------------------------------------*
 ** DATE          Module              DESCRIPTION                             *
 ** 22/09/2013    Hardware Composer   Responsible for processing some         *
 **                                   Hardware layers. These layers comply    *
 **                                   with display controller specification,  *
 **                                   can be displayed directly, bypass       *
 **                                   SurfaceFligner composition. It will     *
 **                                   improve system performance.             *
 ******************************************************************************
 ** File: SprdVirtualDisplayDevice.h  DESCRIPTION                             *
 **                                   Manager Virtual Display device.         *
 ******************************************************************************
 ******************************************************************************
 ** Author:         zhongjun.chen@spreadtrum.com                              *
 *****************************************************************************/

#ifndef _SPRD_VIRTUAL_DISPLAY_DEVICE_H_
#define _SPRD_VIRTUAL_DISPLAY_DEVICE_H_

#include <stdio.h>
#include <stdlib.h>
#include <hardware/hardware.h>
#include <hardware/gralloc.h>
#include <hardware/hwcomposer.h>

#include <cutils/log.h>

#include "../SprdHWLayer.h"
#include "SprdVDLayerList.h"
#include "SprdVirtualPlane.h"
#include "../SprdDisplayDevice.h"
#include "SprdWIDIBlit.h"
#include "../AndroidFence.h"
#include "../dump.h"

using namespace android;

class SprdVirtualDisplayDevice {
public:
    SprdVirtualDisplayDevice();
    ~SprdVirtualDisplayDevice();

    /*
     *  Display configure attribution.
     * */
    int getDisplayAttributes(DisplayAttributes *dpyAttributes);

    /*
     *  Asynchronously update the location of the cursor layer.
     * */
    int setCursorPositionAsync(int x_pos, int y_pos);

    /*
     *  Traversal Virtual Display layer list.
     *  Find which layers comply with Virtual Display standards.
     * */
    int prepare(hwc_display_contents_1_t *list, unsigned int accelerator);

    /*
     *  Post found layers to Virtual Display Device.
     * */
    int commit(hwc_display_contents_1_t *list);

    /*
     *  Init Virtual Display.
     * */
    int Init();

private:
    SprdVDLayerList *mLayerList;
    SprdVirtualPlane *mDisplayPlane;
    sp<SprdWIDIBlit> mBlit;
    bool mHWCCopy;
    int mDebugFlag;
    int mDumpFlag;

};

#endif  // #ifndef _SPRD_VIRTUAL_DISPLAY_DEVICE_H_
