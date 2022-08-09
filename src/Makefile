objects=main.o add.o
CFLGES=-W -Wall -O2 -std=c++17
all : main.out
main.out: $(objects)
	g++ $(CFLGES) $(objects) -o main.out
main.o:main.cpp
	g++ $(CFLGES) -c  main.cpp
add.o: add.cpp
	g++ $(CFLGES) -c  add.cpp
clean :
	rm *.o main.out
