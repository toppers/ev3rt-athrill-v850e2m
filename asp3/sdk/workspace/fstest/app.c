// tag::tracer_def[]
#include "app.h"
#include <stdio.h>
#include <math.h>

// end::tracer_def[]
// tag::main_task[]
void main_task(intptr_t unused) {
    FILE *fp = fopen("fstest.txt","w");
    if ( fp ) {
	syslog(LOG_NOTICE,"succeed\n");
    } else {
	syslog(LOG_NOTICE,"failed\n");
    }

    const char p[] = "abcdefg";
    fwrite(p,sizeof(p),1,fp);
    fclose(fp);

    fp = fopen("fstest.txt","r");

    char buf[100];
    fread(buf,sizeof(buf),1,fp);
     syslog(LOG_NOTICE,buf);
    if ( !strcmp(p,buf) ) {
	syslog(LOG_NOTICE,"succeed cmp\n");
    } else {
	syslog(LOG_NOTICE,"failed cmp\n");
    }

    
    fclose(fp);


}
// end::main_task[]
