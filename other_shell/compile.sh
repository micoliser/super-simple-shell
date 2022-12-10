#!/bin/bash

clear

echo "Compiling . . ."

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 util_funcs.c tests_rss/test.c -o testexec

if [[ $? == 0 ]]; then
	echo -e "\tCompilation successful, No errors encountered\n"
	sleep 1
else
	echo -e "Unable to compile file, Resolve the errors above\n"
	exit 1
fi

echo -e "Running testexec with valgrind . . .\n"

valgrind ./testexec
