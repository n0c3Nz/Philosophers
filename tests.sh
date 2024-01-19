#!/bin/bash

# Test para comprobar número de filósofos DIED por ejecución
#./Philosophers 100 800 400 401 | grep "died" && echo "----"
is_philo=$(ls | grep "Philosophers")
if [ -z "$is_philo" ]; then
	echo "Philosophers executable not found"
	exit 1
echo "------------------------------------------"
else
	while true; do
		echo -en "test 1 [ 100 threads ]\t"; ./Philosophers 100 800 400 401 | grep "died" && echo "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤"
		echo -en "test 2 [ 100 threads ]\t"; ./Philosophers 100 800 401 400 | grep "died" && echo "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤"
		echo -en "test 3 [ 100 threads ]\t"; ./Philosophers 100 800 400 400 | grep "died" && echo "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤"
		echo -en "test 4 [ 153 threads ]\t"; ./Philosophers 153 500 201 301 | grep "died" && echo "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤"
		echo -en "test 5 [ 3 threads ]\t"; ./Philosophers 3 500 300 201 | grep "died" && echo "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤"
		echo -en "test 6 [ 3 threads ]\t"; ./Philosophers 3 500 201 300 | grep "died" && echo "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤"
		echo -en "test 7 [ 3 threads ]\t"; ./Philosophers 3 700 301 400 | grep "died" && echo "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤"
		echo -en "test 8 [ 2 threads ]\t"; ./Philosophers 2 500 300 201 | grep "died" && echo "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤"
		echo -en "test 9 [ 50 threads ]\t"; ./Philosophers 50 700 201 500 | grep "died"
		echo "------------------------------------------"
	done
fi
