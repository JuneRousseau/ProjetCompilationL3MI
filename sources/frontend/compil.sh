#!/bin/bash

flex $1 && bison -v -d $2".y" && gcc lex.yy.c $2".tab.c" strucit_type.c strucit_utils.c strucit_symbols.c -o $2.out -lfl
