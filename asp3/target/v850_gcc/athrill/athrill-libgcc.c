#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "athrill_syscall.h"

unsigned int athrill_device_func_call __attribute__ ((section(".athrill_device_section")));


//void *__dso_handle=0;

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
int  _EXFUN(_fflush_r, (struct _reent *_a, FILE *_b))
{
	// TODO:
	return -1;
}
void _cleanup_r(void)
{

}

static const char *ev3rtfs_top_dir = "_ev3rtfs";
static int is_top_dir_set = 0;

 FILE * _EXFUN(fopen, (const char *__restrict file_name, const char *__restrict mode))
{
	if ( !is_top_dir_set ) {
		// check and set top_dir(only for first time)
		if ( athrill_set_virtfs_top(ev3rtfs_top_dir) == -1 ) {
			return 0;
		}
		is_top_dir_set = 1;
	}
	return (FILE *)athrill_posix_fopen((sys_addr)file_name,(sys_addr)mode);
}
int fclose(FILE *fp)
{
	return athrill_posix_fclose((sys_addr)fp);
}

size_t _EXFUN(fread, (_PTR __restrict buf, size_t size, size_t n, FILE *__restrict fp))
{
	return athrill_posix_fread((sys_addr)buf, size, n, (sys_addr)fp);
}

size_t _EXFUN(fwrite, (const _PTR __restrict buf, size_t size, size_t n, FILE * fp))
{
	return athrill_posix_fwrite((sys_addr)buf, size, n, (sys_addr)fp);
}


int _EXFUN(fflush, (FILE *fp))
{
	return athrill_posix_fflush((sys_addr)fp);
}



FILE * _EXFUN(fdopen, (int a, const char *b))
{
	//TODO syscall
	return NULL;
}
