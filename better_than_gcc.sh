#!/bin/bash

output="_3.c"

print_line()
{
    cpt=1
    num=$1
    realnum=$((num-1))
    
    while read line
    do
	if [ $cpt == $realnum ]
	then
	    echo -e "$line "
	fi
	cpt=$((cpt+1))
    done < $2
}
	

test_compilation()
{
    file=$1
    if [ -f "./Tests/$file" ]
    then
	echo ---------- $file ----------
	echo
	touch compil_log
	name=${file%%.*}
	name_output="./outputs/$name$output"
	(./sources/frontend/structfe.out < ./Tests/$file) > $name_output 2>compil_log
	compil="$?"	
	if [ $compil == 0 ]
	then
	    echo $file: Compilation OK
	    touch test_log
	    (./sources/backend/structbe.out < $name_output) 2>test_log
	    parse="$?"
	    if [ $parse == 0 ]
	    then
		echo $name_output: Accepted
	    else
		echo $name_output: Refused
		cat test_log
		print_line $parse $name_output
	    fi
	    rm test_log
	else
	    if [ $compil == 1 ]
	    then
		echo $file: Compilation Syntax error
	    else
		if [ $compil == 2 ]
		then
		    echo $file: Compilation Semantic error
	        else
		    echo $file: Compilation Another error
		fi
	    fi
	fi
	if [ $answer == 'y' ]
	    then
		cat compil_log
	    fi
	echo
	rm compil_log
    fi
}


echo -e "Voulez vous compiler le structfe ? [y ou n]: \c"
read answer
compilation=0
if [ $answer == 'y' ]
then
    cd ./sources/frontend
    touch log
    ./compil.sh ANSI-frontend.l structfe >log 2>log
    compilation=$?
    cat log
    if [ $compilation != 0 ]
    then
	echo "Compilateur non recompile (fail):"
	cat log
    fi
    rm log
    cd ../..
fi

if [ $compilation == 0 ]
   then
       echo -e "Voulez-vous lire la sortie erreur sur le terminal? [y ou n]: \c"
       read answer
       
       if [ $# == 0 ]
       then
	   list_file=`ls ./Tests`
       else
	   list_file=$@
       fi
    for f in $list_file
    do
	test_compilation $f
    done
fi
       
