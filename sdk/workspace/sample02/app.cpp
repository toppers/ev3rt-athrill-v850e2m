#include "app.h"
#include "util.h"

#include "Motor.h"
#include "Clock.h"

using namespace ev3api;
// tag::walker_def[]
class Walker {
public:
  Walker();
  void run();

private:
  Motor leftWheel;
  Motor rightWheel;
  Clock clock;

  const int8_t pwm = (Motor::PWM_MAX) / 6;
  const uint32_t duration = 2000;

protected:             // <1>
  void forward(void);  // <2>
  void back(void);     // <2>
  void stop(void);     // <2>
};
// end::walker_def[]
// tag::walker_impl_1[]
Walker::Walker():
  leftWheel(PORT_C), rightWheel(PORT_B) {
}

void Walker::forward(void) {  // <1>
  msg_f("Forwarding...", 1);
  leftWheel.setPWM(pwm);
  rightWheel.setPWM(pwm);
}

void Walker::back(void) {  // <1>
  msg_f("Backwarding...", 1);
  leftWheel.setPWM(-pwm);
  rightWheel.setPWM(-pwm);
}

void Walker::stop(void) {  // <1>
  msg_f("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
}
// end::walker_impl_1[]
// tag::walker_impl_2[]
void Walker::run() {
  init_f(__FILE__);
  while(1) {
    forward();             // <1>
    clock.sleep(duration);
    back();                // <1>
    clock.sleep(duration);

    // 左ボタンを長押し、それを捕捉する
    if (ev3_button_is_pressed(LEFT_BUTTON)) {
      break;
    }
  }

  stop();                // <1>
  while(ev3_button_is_pressed(LEFT_BUTTON)) {
    ;
  }
}
// end::walker_impl_2[]
// tag::main_task[]
void main_task(intptr_t unused) {
  Walker walker;
  walker.run();
  ext_tsk();
}
// end::main_task[]
