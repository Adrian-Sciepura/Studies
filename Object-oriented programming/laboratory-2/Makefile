output: main.o Book.o Library.o
	g++ main.o Book.o Library.o -o app.out

main.o: main.cpp
	g++ -c main.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp

Library.o: Library.cpp Library.h
	g++ -c Library.cpp