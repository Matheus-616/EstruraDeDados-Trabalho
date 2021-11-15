#!/bin/bash

gcc -c lista.c 
gcc -c Fila.c
gcc -c pilha.c
gcc -c rede_social.c 
gcc -c main.c 
gcc -o ex lista.o rede_social.o Fila.o pilha.o main.o
./ex