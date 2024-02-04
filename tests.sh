#!/bin/bash
# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;30m'
BLUE='\033[0;34m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# Test para comprobar retraso en la muerte de un filósofo y cuantos filósofos mueren

is_philo=$(ls | grep "Philosophers")
if [ -z "$is_philo" ]; then
    echo -e "$RED$BOLD \rPhilosophers executable not found$NC"
    exit 1
fi

random_commands=(
    "./Philosophers 100 800 400 401 20 | grep 'died' -A3"
    "./Philosophers 100 800 401 400 20 | grep 'died -A3"
    "./Philosophers 100 800 400 400 20 | grep 'died' -A3"
    "./Philosophers 153 500 201 301 20 | grep 'died' -A3"
    "./Philosophers 3 500 300 201 20 | grep 'died' -A3"
    "./Philosophers 3 500 201 300 20 | grep 'died' -A3"
    "./Philosophers 3 700 301 400 20 | grep 'died' -A3"
    "./Philosophers 2 500 300 201 20 | grep 'died' -A3"
    "./Philosophers 50 700 201 500 20 | grep 'died' -A3"
)
moreat_commands=(
	"./Philosophers 6 800 501 301 | grep 'died' -A3"
	"./Philosophers 5 800 501 300 | grep 'died' -A3"
	"./Philosophers 2 300 202 99 | grep 'died' -A3"
	"./Philosophers 60 400 301 100 | grep 'died' -A3"
)
moresleep_commands=(
	"./Philosophers 6 800 300 501 | grep 'died' -A3"
	"./Philosophers 5 700 200 501 | grep 'died' -A3"
	"./Philosophers 23 500 99 401 | grep 'died' -A3"
	"./Philosophers 60 900 200 701 | grep 'died' -A3"
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