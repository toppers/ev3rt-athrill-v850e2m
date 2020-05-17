// tag::tracer_def[]
#include "app.h"
#include <stdio.h>
#include <math.h>
#define CHECK(title, cond) \
	if ( (cond) ) { \
		syslog(LOG_NOTICE, #title ": suceeded \n"); \
	} else { \
		syslog(LOG_NOTICE, #title ": failed \n"); \
	}		
// end::tracer_def[]
// tag::main_task[]
void main_task(intptr_t unused) {

    ev3_sensor_config(EV3_PORT_1,GYRO_SENSOR);
    ev3_motor_config(EV3_PORT_A,LARGE_MOTOR);
    ev3_motor_set_power(EV3_PORT_A,20);
    int i = 0;
    while(1) {
	int cur = ev3_battery_current_mA();
	int vol = ev3_battery_voltage_mV();
	syslog(LOG_NOTICE,"cur=%d\n vol=%d\n",cur,vol);
	i++;
	if ( i % 5 == 0 ) {
		ev3_gyro_sensor_reset(EV3_PORT_1);
		ev3_motor_reset_counts(EV3_PORT_A);
	}
	tslp_tsk(1000000);
    }
}


// end::main_task[]
