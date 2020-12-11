all:	
		clear
		gcc main.c processor.c -o epidemic

clean:
		rm -f epidemic