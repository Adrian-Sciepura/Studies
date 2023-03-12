output: main.o Book.o
	g++ main.o Book.o -o app.out

main.o: main.cpp
	g++ -c main.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp
