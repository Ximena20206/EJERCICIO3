#!/bin/bash


gcc ejercicio3.c tiempo.c tiempo.h -o e

echo  2500 ascendente >> e3.txt
./e 2500 2500asc.txt >> e3.txt

echo  5000 ascendente >> e3.txt
./e 5000 5000asc.txt >> e3.txt

echo  2500 primero >> e3.txt
./e 2500 2500primero.txt >> e3.txt

echo  5000 primero >> e3.txt
./e 5000 5000primero.txt >> e3.txt


gcc e3casomedio.c tiempo.c tiempo.h -o em

echo  2500 enmedio >> e3.txt
for i in {1..1000}; do
	./em 2500 2500enmedio.txt >> e3.txt
done
echo ---------------------------------------------------->> e3.txt
echo  5000 enmedio >> e3.txt
for i in {1..1000}; do	  
	./em 5000 5000enmedio.txt >> e3.txt
done





