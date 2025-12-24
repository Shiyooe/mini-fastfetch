#include <stdio.h>
#include "colors.h"
#include "os.h"
#include "cpu.h"
#include "memory.h"
#include "uptime.h"
#include "ascii.h"
#include "gpu.h"
#include "kernel.h"
#include "version.h"




int main() {
    char os[128], cpu[128], gpu[256], kernel[128];
    long ram_used, ram_total;
    int h, m;

    get_os(os);
    get_cpu(cpu);
    get_gpu(gpu);
    get_kernel(kernel);
    get_memory(&ram_used, &ram_total);
    get_uptime(&h, &m);

    print_ascii(os);

    #define LABEL(color, text) color text C_RESET

    printf(LABEL(C_BLUE,"OS:      ") "%s\n", os);
    printf(LABEL(C_BLUE,"Kernel:  ") "%s\n", kernel);
    printf(LABEL(C_BLUE,"CPU:     ") "%s\n", cpu);
    printf(LABEL(C_BLUE,"GPU:    ") "%s\n", gpu);
    printf(LABEL(C_BLUE,"RAM:     ") "%ldMB / %ldMB\n", ram_used, ram_total);
    printf(LABEL(C_BLUE,"Uptime:  ") "%dh %dm\n", h, m);


    return 0;
}
