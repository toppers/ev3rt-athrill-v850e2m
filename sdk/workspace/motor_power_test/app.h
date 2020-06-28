
#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"

#include "target_test.h"

#ifndef STACK_SIZE
#define STACK_SIZE      4096 
#endif /* STACK_SIZE */

#define MAIN_PRIORITY	TMIN_APP_TPRI + 1

#ifndef TOPPERS_MACRO_ONLY
	extern void main_task(intptr_t exinf);
	extern void motor_control_task(intptr_t exinf);
#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
