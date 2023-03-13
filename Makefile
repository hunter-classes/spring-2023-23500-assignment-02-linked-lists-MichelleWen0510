main: main.o OList.o Node.o
	g++ -o main main.o OList.o Node.o

tests: tests.o OList.o Node.o
	g++ -o tests tests.o OList.o Node.o

main.o: main.cpp OList.h Node.h

tests.o: tests.cpp OList.h Node.h

OList.o: OList.cpp OList.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f *.o
