/******************************************************************************
 *  LineTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "LineMonitor.h"
#include "Walker.h"

class LineTracer {
public:
    LineTracer(const LineMonitor* lineMonitor,
               Walker* walker);

    void run();

private:
    const LineMonitor* mLineMonitor;
    Walker* mWalker;
    bool mIsInitialized;

    int calcDirection(bool isOnLine);
};

#endif  // EV3_APP_LINETRACER_H_
