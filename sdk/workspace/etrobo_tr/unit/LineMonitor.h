/******************************************************************************
 *  LineMonitor.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineMonitor
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_UNIT_LINEMONITOR_H_
#define EV3_UNIT_LINEMONITOR_H_

#include "ColorSensor.h"

// 定義
class LineMonitor {
public:
    explicit LineMonitor(const ev3api::ColorSensor& colorSensor);

    bool isOnLine() const;
    void setThreshold(int8_t threshold);

private:
    static const int8_t INITIAL_THRESHOLD;

    const ev3api::ColorSensor& mColorSensor;
    int8_t mThreshold;
};

#endif  // EV3_UNIT_LINEMONITOR_H_
