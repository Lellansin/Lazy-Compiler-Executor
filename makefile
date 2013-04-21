
CC = gcc -g
OBJ = lce.o str.o file.o

lce: main install
	echo "install ok"

main: ${OBJ}
	${CC} $^ -o lce

.c.o:
	${CC} -c $< -o $@

clear: uninstall
	rm -rf *.o lce test

install:
	cp lce /usr/bin

uninstall:
	rm -rf /usr/bin/lce
