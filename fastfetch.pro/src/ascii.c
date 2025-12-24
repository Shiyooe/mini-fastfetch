#include <stdio.h>
#include <string.h>
#include "ascii.h"
#include "colors.h"

void print_ascii(const char *os) {
    if (strstr(os, "Arch")) {
        printf(C_CYAN
            "       .\n"
            "      / \\\n"
            "     /   \\\n"
            "    /\\    \\\n"
            "   /       \\\n"
            "  /   /\\    \\\n"
            " /___/  \\____\\\n" C_RESET);
    } else {
        printf(C_GREEN
            "   ____\n"
            "  |    |\n"
            "  |____|\n" C_RESET);
    }
}
