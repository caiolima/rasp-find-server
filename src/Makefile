.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	rasp-find

rasp-find: main.o
	g++ -o $@ $^

clean:
	rm *.o *.*~ rasp-find-server

