all:
	gcc -Wall -Werror main.c -o main -pthread	



.PHONY: run

run:
	./main 
