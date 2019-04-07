#!/bin/sh

MAIN=$1
NAME=${2:-main_test}

gcc -o ${NAME} ${MAIN} libft_malloc.so