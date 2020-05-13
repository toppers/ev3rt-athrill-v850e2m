#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "athrill_syscall.h"

unsigned int athrill_device_func_call __attribute__ ((section(".athrill_device_section")));


//void *__dso_handle=0;
#if 0
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
#endif 
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
#if 0
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
#endif

static const char *ev3rtfs_top_dir = "_ev3rtfs";
static int is_top_dir_set = 0;


int _close_r _PARAMS ((struct _reent *unused, int fd))
{
	return athrill_newlib_close_r(fd);
}

_off_t _lseek_r _PARAMS ((struct _reent *unused, int fd, _off_t offset, int whence))
{
	return (_off_t) athrill_newlib_lseek_r(fd,offset,whence);
}

int _open_r _PARAMS ((struct _reent *unused, char *file_name, int flags, int mode))
{
	if ( !is_top_dir_set ) {
		// check and set top_dir(only for first time)
		if ( athrill_set_virtfs_top((sys_addr)ev3rtfs_top_dir) == -1 ) {
			return 0;
		}
		is_top_dir_set = 1;
	}

	return athrill_newlib_open_r(file_name, flags, mode);
}

_ssize_t _read_r _PARAMS ((struct _reent *unused, int fd, void *buf, size_t size))
{
	return (_ssize_t)athrill_newlib_read_r(fd, buf, size);	
}

_ssize_t _write_r _PARAMS ((struct _reent *unused, int fd, const void *buf, size_t size))
{
	return (_ssize_t)athrill_newlib_write_r(fd, buf, size);
}

#if 0 // For fopen optimization
 FILE * _EXFUN(fopen, (const char *__restrict file_name, const char *__restrict mode))
{
	if ( !is_top_dir_set ) {
		// check and set top_dir(only for first time)
		if ( athrill_set_virtfs_top((sys_addr)ev3rtfs_top_dir) == -1 ) {
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
#endif
