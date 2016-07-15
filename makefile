#Compilador
CC=g++
#Flags
CXXFLAGS=-pthread -std=c++11
#Executavel
EXEC=nQueens
#Arquivos cpp
SRC=$(wildcard src/*.cpp)
#Arquivos Objetos
OBJ=$(SRC:.c=.o)
#Compila
all: $(SRC)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(EXEC)
#Apaga arquivos gerados
#make clean
clean:
	rm $(EXEC) *~ *.o -f
