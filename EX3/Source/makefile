a.out: main.o myDS.o myAlgo.o myIO.o
	gcc -o a.out main.o myDS.o myAlgo.o myIO.o
main.o: main.c myDS.h myAlgo.h myIO.h
	gcc -c main.c
myAlgo.o: myAlgo.c myAlgo.h
	gcc -c myAlgo.c
myDS.o: myDS.c myDS.h
	gcc -c myDS.c
myIO.o: myIO.c myIO.h
	gcc -c myIO.c
