# My First Makefile

all: main.o function.o
	gcc -o app main.o function.o

main.o: main.c
	gcc -c main.c -I ./

function.o: function.c
	gcc -c function.c -I ./

clean:
	rm -rf *.o
	rm -rf Binary
	rm -rf app.exe
