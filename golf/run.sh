#!/bin/bash
R_VALUE=${1:-20}

# Add necessary includes to the top of ulam.c
sed '1i #include<stdio.h>\n#include<stdlib.h>' ulam.c > Ulam.c

# Compile ulam.c with specified macros and warnings enabled
gcc -Wall -Db\(y,x\)="p[y][x/8]>>(x%8)&1" -Do\(x\)="((1UL<<(x))-1)" -DL="long" -D\$="\"Length %ld\n%ld\n\"" -DR="$R_VALUE" Ulam.c -o ulam

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    ./ulam

    # Capture the exit status of the program
    PROGRAM_EXIT_STATUS=$?

    # Delete the executable
    rm -f ulam
    rm -f Ulam.c

    # Exit with the program's exit status
    exit $PROGRAM_EXIT_STATUS
else
    echo "Compilation failed."
    exit 1
fi
