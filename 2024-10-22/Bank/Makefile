MyBank: main.o bank.o
	g++ main.o bank.o -o MyBank
main.o: main.cpp
	g++ -c main.cpp
bank.o: bank.cpp
	g++ -c bank.cpp
clean:
	rm -r MyBank *.o