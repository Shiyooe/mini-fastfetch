#include <sys/utsname.h>
#include <string.h>
#include "kernel.h"

void get_kernel(char *out) {
    struct utsname uts;
    uname(&uts);
    strcpy(out, uts.release);
}
