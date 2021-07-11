all:
	g++ -shared ./lib/*.cpp -o ../bin/API.dll
	g++ main.cpp -L../bin -lAPI -Wall -o ../bin/main

clean:
	rm -f ../bin/*.o

run:
	../bin/main