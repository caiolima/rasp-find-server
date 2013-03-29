.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	rasp-find-server

rasp-find-server: main.o
	gcc -o $@ $^

clean:
	rm *.o *.*~ rasp-find-server

