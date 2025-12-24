#include <stdio.h>
#include <string.h>
#include "cpu.h"

void get_cpu(char *out) {
    FILE *f = fopen("/proc/cpuinfo", "r");
    if (!f) {
        strcpy(out, "Unknown");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "model name", 10) == 0) {
            char *p = strchr(line, ':');
            strcpy(out, p + 2);
            out[strcspn(out, "\n")] = 0;
            break;
        }
    }
    fclose(f);
}
