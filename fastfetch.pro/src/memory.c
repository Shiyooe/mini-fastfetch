#include <sys/sysinfo.h>
#include "memory.h"

void get_memory(long *used, long *total) {
    struct sysinfo info;
    sysinfo(&info);

    *total = info.totalram / 1024 / 1024;
    long free = info.freeram / 1024 / 1024;
    *used = *total - free;
}
