#!/bin/bash

cd ./../../Tests
output="_3.c"
for file in `ls .`
do
    if [ -f "$file" ]
    then
	echo ---------- $file ----------
	echo
	name=${file%%.*}
	name_output="./outputs/$name$output"
	(./../sources/frontend/structfe < $file) > $name_output
	code="$?"
	echo
	if [ $code == 0 ]
	then
	    echo $file: OK
	else
	    if [ $code == 1 ]
	    then
		echo $file: Syntax error
	    else
		if [ $code == 2 ]
		then
		    echo $file: Semantic error
	        else
		    echo $file: Another error
		fi
	    fi
	fi
	echo
    fi
done
