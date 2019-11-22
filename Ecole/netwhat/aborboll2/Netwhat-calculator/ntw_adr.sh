#binbashthing
#!/bin/bash

#compiling
gcc -Wall -Wextra -Werror  ./srcs/nt_ntw_adr.c

#run with argv1 as argument
./a.out "$1"
