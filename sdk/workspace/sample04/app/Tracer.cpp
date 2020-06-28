#include "Tracer.h"

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B),
  colorSensor(PORT_3) {
  }

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
}

void Tracer::run() {
  const float Kp = 0.83;        // 比例係数
  const int target = 10;        // 白・黒の中間値
  const int bias = 0;
  
  msg_f("running...", 1);
  int diff = colorSensor.getBrightness() - target;
  float turn = Kp * diff + bias;
  leftWheel.setPWM(pwm - turn);
  rightWheel.setPWM(pwm + turn);
}
