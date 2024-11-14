#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> 
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

static long posix_version = 0;
static long xsi_version = 0;

static long pathmax = PATH_MAX;

char *path_alloc(size_t *sizep)
{
    char  *ptr; 
    size_t size;

    if(posix_version == 0)
        posix_version = sysconf(_SC_XOPEN_VERSION);

    if(xsi_version == 0)
        xsi_version = sysconf(_SC_XOPEN_VERSION);
    
    
    if((posix_version < 200112L) && (xsi_version < 4))
        size = pathmax + 1;
    else 
        size = pathmax; 
    
    if((ptr = malloc(size)) == NULL)
        perror("error");
    if(sizep != NULL)
        *sizep = size; 

    return (ptr);

}

typedef int Myfunc(const char *, const struct stat *, int);

static Myfunc myfunc; 
static int myftw(char *, Myfunc *);
static int dopath(Myfunc *);

static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot; 

int
main(int argc, char *argv[])
{

}

#define FTW_F       1;
#define FTW_D       2;
#define FTW_DNR     3;
#define FTW_NS      4;

static char *fullpath; 
static size_t pathlen; 

static int

myftw(char *pathname, Myfunc *func)
{
    fullpath = path_alloc(&pathlen);
    if(pathlen <= strlen(pathname))
    {
        pathlen = strlen(pathname) * 2;
        if((fullpath = realloc(fullpath, pathlen)) == NULL)
            err_sys("realloc failed");
    }
    strcpy(fullpath, pathname);
    return (dopath(func));
}