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
	if [ $? == 0 ]
	then
	    echo $file: OK
	else
	    echo $file: ERROR
	fi
	echo
	echo
    fi
done
