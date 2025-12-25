# fastfetch-pro

Minimal fastfetch clone written in C for Linux.

## Features
- OS, Kernel, CPU, GPU
- RAM & Uptime
- ANSI colors
- ASCII distro logo
- Modular codebase

## Build
```bash
make

## Output example
make
./fastfetch-pro

rm -f fastfetch-pro
gcc -Wall -Wextra -Iinclude src/*.c -o fastfetch-pro
       .
      / \
     /   \
    /\    \
   /       \
  /   /\    \
 /___/  \____\
OS:      Arch Linux
Kernel:  6.18.2-arch2-1
CPU:     Intel(R) Core(TM) i5-8350U CPU @ 1.70GHz
GPU:     Intel Corporation UHD Graphics 620 (rev 07)
RAM:     3342MB / 7809MB
Uptime:  0h 6m
