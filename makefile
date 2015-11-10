main : main.o CardPool.o Card.o
	g++ main.o CardPool.o Card.o -o main
	
main.o : main.cpp 
	g++ -c main.cpp
CardPool.o : CardPool.cpp
	g++ -c CardPool.cpp
Card.o : Card.cpp
	g++ -c Card.cpp
clean :
	rm main.o CardPool.o Card.o