#!/bin/bash
# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;30m'
BLUE='\033[0;34m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# Test para comprobar número de filósofos DIED por ejecución
#./Philosophers 100 800 400 401 | grep "died" && echo "----"
is_philo=$(ls | grep "Philosophers")
if [ -z "$is_philo" ]; then
    echo "Philosophers executable not found"
    exit 1
fi


random_commands=(
    "./Philosophers 100 800 400 401 | grep 'died'"
    "./Philosophers 100 800 401 400 | grep 'died'"
    "./Philosophers 100 800 400 400 | grep 'died'"
    "./Philosophers 153 500 201 301 | grep 'died'"
    "./Philosophers 3 500 300 201 | grep 'died'"
    "./Philosophers 3 500 201 300 | grep 'died'"
    "./Philosophers 3 700 301 400 | grep 'died'"
    "./Philosophers 2 500 300 201 | grep 'died'"
    "./Philosophers 50 700 201 500 | grep 'died'"
)
moreat_commands=(
	"./Philosophers 6 800 501 301 | grep 'died'"
	"./Philosophers 5 800 501 300 | grep 'died'"
	"./Philosophers 23 800 601 200 | grep 'died'"
	"./Philosophers 60 800 601 200 | grep 'died'"
)
moresleep_commands=(
	"./Philosophers 6 800 300 501 | grep 'died'"
	"./Philosophers 5 800 300 501 | grep 'died'"
	"./Philosophers 23 900 200 701 | grep 'died'"
	"./Philosophers 60 900 200 701 | grep 'died'"
)
#for command in "${commands[@]}"; do
#    echo -en "Ejecutando comando: $command\n"
#    eval "$command"
#done

function printer()
{
	local commands=("$@")
	for command in "${commands[@]}"; do
		echo -en "$command\n" | cut -d' ' -f2-5
		target=$(echo -en "$command\n" | cut -d' ' -f3)
		result=$(eval  timeout 20 "$command")
		filtered=$(echo "$result" |  awk 'NR==1 {print $1}' | tr -d 'ms')
		echo "$result"
		if [[ $filtered -lt $(($target + 9)) ]]; then
			tput cuu1
			echo -en "\t\t\033[32m✔\033[0m"
			echo -e '\n\033[0;32m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\033[0m'
		else
			tput cuu1
			echo -en "\t\t\033[31m✘\033[0m"
			echo -e '\n\033[0;31m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\033[0m'
		fi
	done
}

if [[ "$@" == *"-moreat"* ]]; then
	printer "${moreat_commands[@]}"
    echo -e "\n$BLUE \rSe proporcionó el argumento $ORANGE$BOLD-moreat$NC\n"
fi

if [[ "$@" == *"-moresleep"* ]]; then
	printer "${moresleep_commands[@]}"
    echo -e "\n$BLUE \rSe proporcionó el argumento $ORANGE$BOLD-moresleep$NC\n"
fi

if [[ "$@" == *"-random"* ]]; then
	printer "${random_commands[@]}"
    echo -e "\n$BLUE \rSe proporcionó el argumento $ORANGE$BOLD-random$NC\n"
fi