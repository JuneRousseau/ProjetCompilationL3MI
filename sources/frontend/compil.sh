#!/bin/bash

flex $1 &&
bison -v -d $2".y" &&
gcc lex.yy.c $2".tab.c" -o $2 -lfl
