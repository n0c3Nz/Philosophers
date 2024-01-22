#!/bin/bash

# Test para comprobar número de filósofos DIED por ejecución
#./Philosophers 100 800 400 401 | grep "died" && echo "----"
is_philo=$(ls | grep "Philosophers")
if [ -z "$is_philo" ]; then
    echo "Philosophers executable not found"
    exit 1
fi
echo "------------------------------------------"

random_commands=(
    "./Philosophers 100 800 400 401 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
    "./Philosophers 100 800 401 400 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
    "./Philosophers 100 800 400 400 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
    "./Philosophers 153 500 201 301 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
    "./Philosophers 3 500 300 201 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
    "./Philosophers 3 500 201 300 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
    "./Philosophers 3 700 301 400 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
    "./Philosophers 2 500 300 201 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
    "./Philosophers 50 700 201 500 | grep 'died'"
)
moreat_commands=(
	"./Philosophers 6 800 501 300 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
	"./Philosophers 5 800 501 300 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
	"./Philosophers 23 800 601 200 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
	"./Philosophers 60 800 601 200 | grep 'died'"
)
moresleep_commands=(
	"./Philosophers 6 800 300 501 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
	"./Philosophers 5 800 300 501 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
	"./Philosophers 23 900 200 701 | grep 'died' && echo '⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤'"
	"./Philosophers 60 900 200 701 | grep 'died'"
)
#for command in "${commands[@]}"; do
#    echo -en "Ejecutando comando: $command\n"
#    eval "$command"
#done

if [[ "$@" == *"-moreat"* ]]; then
    for command in "${moreat_commands[@]}"; do
    	echo -en "Ejecutando comando: $command\n" | cut -d' ' -f4-7
    	eval  timeout 20 "$command"
	done
    echo "Se proporcionó el argumento -moreat"
fi

if [[ "$@" == *"-moresleep"* ]]; then
    for command in "${moresleep_commands[@]}"; do
    	echo -en "Ejecutando comando: $command\n" | cut -d' ' -f4-7
    	eval  timeout 20 "$command"
	done
    echo "Se proporcionó el argumento -moresleep"
fi

if [[ "$@" == *"-random"* ]]; then
    for command in "${random_commands[@]}"; do
    	echo -en "Ejecutando comando: $command\n" | cut -d' ' -f4-7
    	eval  timeout 20 "$command"
	done
    echo "Se proporcionó el argumento -random"
fi