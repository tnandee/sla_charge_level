#!/bin/sh

gcc -o main main.c

unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     ./main;;
    CYGWIN*)    ./main.exe;;
    *)          echo "UNKNOWN:${unameOut}"
esac


