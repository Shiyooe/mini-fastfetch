#include <stdio.h>
#include <string.h>
#include "os.h"

void get_os(char *out) {
    FILE *f = fopen("/etc/os-release", "r");
    if (!f) {
        strcpy(out, "Unknown");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "PRETTY_NAME=", 12) == 0) {
            char *s = strchr(line, '"');
            char *e = strrchr(line, '"');
            strncpy(out, s + 1, e - s - 1);
            out[e - s - 1] = 0;
            break;
        }
    }
    fclose(f);
}
