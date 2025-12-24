#include <stdio.h>
#include <string.h>
#include "gpu.h"

void get_gpu(char *out) {
    FILE *fp = popen("lspci | grep -E 'VGA|3D'", "r");
    if (!fp) {
        strcpy(out, "Unknown");
        return;
    }

    fgets(out, 256, fp);
    pclose(fp);

    char *p = strstr(out, "controller:");
    if (p) {
        memmove(out, p + 11, strlen(p));
    }

    out[strcspn(out, "\n")] = 0;
}
