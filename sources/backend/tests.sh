#!/bin/bash

cd ./../../Tests/outputs
for file in `ls .`
do
    if [ -f "$file" ]
    then
	(./../../sources/backend/structbe < $file)
	code="$?"
	if [ $code == 0 ]
	then
	    echo $file: Accepted
	else
	    echo $file: Refused
	fi
	echo
    fi
done
