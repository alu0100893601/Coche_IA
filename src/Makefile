CC=g++
CXXFLAGS=-std=c++11

OBJS = main.o Tablero.o Coche.o Camino.o Nodo.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o cochito.exe ${OBJS}

clean:
	rm -rf *.o cochito.exe
