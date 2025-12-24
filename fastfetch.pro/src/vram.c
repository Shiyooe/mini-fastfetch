#include <stdio.h>
#include <stdlib.h>
#include "vram.h"

void get_vram(long *used, long *total) {
    FILE *f;

    /* NVIDIA */
    f = popen(
        "nvidia-smi --query-gpu=memory.used,memory.total "
        "--format=csv,noheader,nounits 2>/dev/null", "r");
    if (f) {
        if (fscanf(f, "%ld, %ld", used, total) == 2) {
            pclose(f);
            return;
        }
        pclose(f);
    }

    /* Intel / AMD (sysfs) */
    f = fopen("/sys/class/drm/card0/mem_info_vram_total", "r");
    if (f) {
        long bytes;
        fscanf(f, "%ld", &bytes);
        fclose(f);
        *total = bytes / 1024 / 1024;
        *used  = -1; /* unknown */
        return;
    }

    *used = *total = -1;
}
