main: main2.o OList.o Node.o
	g++ -o main main2.o OList.o Node.o

tests: tests.o OList.o Node.o
	g++ -o tests tests.o OList.o Node.o

main2.o: main2.cpp OList.h Node.h

tests.o: tests.cpp OList.h Node.h

OList.o: OList.cpp OList.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f *.o
