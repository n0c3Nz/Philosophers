#!/bin/bash

# Test para comprobar número de filósofos DIED por ejecución
#./Philosophers 100 800 400 401 | grep "died" && echo "----"
echo "------------------------------------------"
while true; do
	echo -en "test 1\t"; ./Philosophers 100 800 400 401 | grep "died" && echo "----"
    echo -en "test 2\t"; ./Philosophers 100 800 401 400 | grep "died" && echo "----"
	echo -en "test 3\t"; ./Philosophers 100 800 400 400 | grep "died" && echo "----"
	echo -en "test 4\t"; ./Philosophers 153 500 201 301 | grep "died" && echo "----"
	echo -en "test 5\t"; ./Philosophers 3 500 300 201 | grep "died" && echo "----"
	echo -en "test 6\t"; ./Philosophers 3 500 201 300 | grep "died"
	echo "------------------------------------------"
done
