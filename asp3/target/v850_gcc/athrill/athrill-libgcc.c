#include <string.h>
#include <stdlib.h>

#include "athrill_syscall.h"

unsigned int athrill_device_func_call __attribute__ ((section(".athrill_device_section")));


void *__dso_handle=0;

void *malloc(size_t size)
{
	return (void*)athrill_posix_malloc((sys_uint32)size);
}
void free(void *addr)
{
	athrill_posix_free((sys_addr)addr);
}

void *calloc(size_t nmemb, size_t size)
{
	return (void*)athrill_posix_calloc((sys_uint32)nmemb, (sys_uint32)size);
}

void *realloc(void *ptr, size_t size)
{
	return (void*)athrill_posix_realloc((sys_addr)ptr, (sys_uint32)size);
}

int raise(int sig)
{
	return 0;
}

//TODO
// need to delete following files from lib.a
// lib_a-exit.o lib_a-__atexit.o lib_a-__call_atexit.o lib_a-fflush.o lib_a-findfp.o lib_a-refill.o
void exit(int status)
{
}

void __register_exitproc(void)
{

}
void __sinit(void)
{

}
void __srefill_r(void)
{

}
void _fflush_r(void)
{

}
void _cleanup_r(void)
{

}
void fflush(void)
{

}

int fopen(void *fp, char *flag)
{
	//TODO syscall
	return 0;
}
int fclose(void *fp)
{
	//TODO syscall
	return 0;
}
void *fdopen(int fd, const char *flag)
{
	//TODO syscall
	return NULL;
}
