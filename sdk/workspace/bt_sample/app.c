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


	int c;
    int i = 0;
	while(1) {
#if 1
        char *p = fgets(buffer, sizeof(buffer), bt);
        if ((p != NULL) && (*p != '\0')) {
#if 1
            int j;
            int len = strlen(buffer) + 1;
            for (j = 0; j < len; j++) {
                syslog(LOG_NOTICE, "%c[0x%x]", buffer[j], buffer[j]);
            }
#endif
            syslog(LOG_NOTICE,"Input was=%s\n",buffer);
            syslog(LOG_NOTICE,"Output is=%s\n",buffer);
            fprintf(bt, "Output is=%s", buffer);
            i++;
        }
#else
		int c = fgetc(bt);
        if (c >= 0) {
            syslog(LOG_NOTICE, "%c[0x%x]", c, c);
            buffer[i++] = c;
            if (c == '\n') {
                if (i > 1) {
                    syslog(LOG_NOTICE,"Input was=%s\n",buffer);
                    syslog(LOG_NOTICE,"Output is=%s\n",buffer);
                    fprintf(bt, "Output is=%s", buffer);
                }
                i = 0;
            }
        }
#endif
		tslp_tsk(1000000);
	}
}
// end::main_task[]
