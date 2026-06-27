#include <errno.h>
#include <sys/stat.h>

int _close(int fd) { return -1; }
int _lseek(int fd, int ptr, int dir) { return 0; }
int _read(int fd, char *ptr, int len) { return 0; }
int _write(int fd, char *ptr, int len) { return len; }
int _fstat(int fd, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _isatty(int fd) { return 1; }
int _getpid(void) { return 1; }
int _kill(int pid, int sig) { errno = EINVAL; return -1; }
void _exit(int status) { while(1); }
void *_sbrk(int incr) {
    extern char _end;
    static char *heap_end = &_end;
    char *prev = heap_end;
    heap_end += incr;
    return (void*)prev;
}
