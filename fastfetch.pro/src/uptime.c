#include <sys/sysinfo.h>
#include "uptime.h"

void get_uptime(int *h, int *m) {
    struct sysinfo info;
    sysinfo(&info);

    *h = info.uptime / 3600;
    *m = (info.uptime % 3600) / 60;
}
