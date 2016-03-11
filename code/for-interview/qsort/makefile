main: main.o qsort.o
	cc -o main main.o qsort.o

main.o: main.c qsort.h
	cc -c main.c 

qsort.o: qsort.c qsort.h
	cc -c qsort.c

clean:
	rm main main.o qsort.o
