#!/linking/compile_time_interpositioning/ctl.sh
# This script compiles the C files and runs the resulting executable.
gcc -Wall -DCOMPILETIME -c mymalloc.c
gcc -Wall -I. -o intc int.c mymalloc.o
./intc 10 100 1000
