// tag::tracer_def[]
#include "app.h"
#include "Tracer.h"
#include "Clock.h"
using namespace ev3api;

Tracer tracer;                  // Tracerのインスタンスを作成
Clock clock;

void tracer_task(intptr_t exinf) {// 周期的に起動される関数
  tracer.run();               // 走行
  ext_tsk();
}
// end::tracer_def[]
// tag::main_task[]
void main_task(intptr_t unused) {
  const uint32_t duration = 100; // 100msec毎にボタンを検出する

  tracer.init(); //tracerの初期化

  sta_cyc(TRACER_CYC); // Tracerタスク起動の周期タスクを起動させる

  while (!ev3_button_is_pressed(LEFT_BUTTON)) { //ボタンが押されるまで繰り返す
      clock.sleep(duration);   // 指定した時間を待つ
  }
  stp_cyc(TRACER_CYC); // Tracerタスクの周期を止める
  tracer.terminate(); // Tracerの動作を止める
  ext_tsk(); // メインタスクの処理を終了
}
// end::main_task[]
