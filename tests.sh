#!/bin/bash

# Test para comprobar número de filósofos DIED por ejecución
#./Philosophers 100 800 400 401 | grep "died" && echo "----"
while true; do
	./Philosophers 100 800 400 401 | grep "died" && echo "----"
        ./Philosophers 100 800 401 400 | grep "died" && echo "----"
done
