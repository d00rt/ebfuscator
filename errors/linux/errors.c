#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/select.h>
#include <wait.h>
#include <sys/socket.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <sys/types.h>

#include "error.h"

void
generate_error_1()
{
   chmod ("/etc/shadow", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);
}

void
generate_error_2()
{
   fopen("nonexist.txt", "rb");
}

void
generate_error_3()
{
    kill(-9999, 0);
}

void
generate_error_10()
{
    int childStatus;
    waitpid(0x29B, &childStatus, WNOHANG);
}

void
generate_error_12()
{
    int tb =  -1;
    (int *) malloc(tb);
}

void
generate_error_13()
{
    fopen ("/etc/shadow", "wb");
}

void
generate_error_14()
{
    char *argv[] = { "/bin/kill"};
    char *envp[] = {};
    execve(argv[0], &argv[0], envp);
}

void
generate_error_17()
{
    mkdir("/etc", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH);
}

void
generate_error_20()
{
    opendir("/bin/ls");
}

void
generate_error_21()
{
    fopen ("/bin", "wb");
}

void
generate_error_22()
{
    select(-1, 0, 0, 0, 0);
}

void
generate_error_24()
{
    while (open("/bin/ls", O_RDONLY) != -1){};
}

void
generate_error_30()
{
    /*
     * We should check to make sure this fs is always on linux and always read-only
     * other approach would be to create a tmp FS only readable
    */
    access("/sys/fs/cgroup", W_OK);
}
