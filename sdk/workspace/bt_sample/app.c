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
    static char buffer[1024];

	// Bluetooth仮想シリアルポートのファイルをオープンする
	FILE *bt = ev3_serial_open_file(EV3_SERIAL_BT);

	// 書式化した文字列をBluetooth仮想シリアルポートへ書き込む
	fprintf(bt, "Bluetooth SPP ID: %d\n", EV3_SERIAL_BT);

	// Bluetooth仮想シリアルポートから1文字を読み取る
	int c;
	while(1) {
		char *p = fgets(buffer, sizeof(buffer), bt);
        if (p != NULL) {
    		syslog(LOG_NOTICE,"Input was=%s\n",p);
    		fprintf(bt, "Output echo: %s\n", p);
        }
		tslp_tsk(1000000);
	}
}
// end::main_task[]
