all: main.c
	gcc -o dirinfo main.c

run: all
	./dirinfo