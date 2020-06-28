/******************************************************************************
 *  Walker.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Implementation of the Class Walker
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "Walker.h"

// 定数宣言
const int Walker::LOW    = 30;    // 低速
const int Walker::NORMAL = 50;    // 通常
const int Walker::HIGH   = 70;    // 高速

const int Walker::RIGHT  = 0;     // 左方向
const int Walker::LEFT   = 1;     // 右方向

/**
 * コンストラクタ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 */
Walker::Walker(ev3api::Motor& leftWheel,
                                 ev3api::Motor& rightWheel)
    : mLeftWheel(leftWheel),
      mRightWheel(rightWheel),
      mForward(LOW),
      mTurn(RIGHT) {
}

/**
 * 走行する
 */
void Walker::run() {
    // 左右モータに回転を指示する
    int rightPWM = 0;
    int leftPWM = 0;
    
    if(mTurn == RIGHT) {
        rightPWM = 0;
        leftPWM = mForward;
    } else if(mTurn == LEFT) {
        rightPWM = mForward;
        leftPWM = 0;
    } else {
        rightPWM = mForward;
        leftPWM = mForward;
    }
    
    mRightWheel.setPWM(rightPWM);
    mLeftWheel.setPWM(leftPWM);
}

/**
 * 走行に必要なものをリセットする
 */
void Walker::init() {
    // モータをリセットする
    mLeftWheel.reset();
    mRightWheel.reset();
}

/**
 * PWM値を設定する
 * @param forward 前進値
 * @param turn    旋回方向
 */
void Walker::setCommand(int forward, int turn) {
    mForward = forward;
    mTurn    = turn;
}
