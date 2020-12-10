all: clean
	gcc main.c processor.c -o main

clean
	rm -f main