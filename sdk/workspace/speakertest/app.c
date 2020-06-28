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

    CHECK(set_volume,ev3_speaker_set_volume(10)==E_OK); 
    CHECK( play_tone, ev3_speaker_play_tone(250,1000) == E_OK);
    memfile_t mf;
    ER err = ev3_memfile_load("fstest.txt",&mf);
    CHECK(memfile,err==E_OK);
    CHECK(speaker_play_file,ev3_speaker_play_file(&mf,1000)==E_OK);
    CHECK(speaker_stop,ev3_speaker_stop()==E_OK);

    while(1) {;}


}
// end::main_task[]
