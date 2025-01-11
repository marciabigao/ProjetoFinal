CC = g++
CFLAGS = -std=c++11 -Wall

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

all:main

$(OBJ_DIR)/jogador.o: $(INCLUDE_DIR)/Jogador.hpp $(SRC_DIR)/Jogador.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogador.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/jogador.o

$(OBJ_DIR)/jogos.o: $(INCLUDE_DIR)/Jogos.hpp $(SRC_DIR)/Jogos.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogos.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/jogos.o

$(OBJ_DIR)/reversi.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/Reversi.hpp $(SRC_DIR)/Reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/reversi.o

$(OBJ_DIR)/jogodavelha.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/JogodaVelha.hpp $(SRC_DIR)/JogodaVelha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/JogodaVelha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/jogodavelha.o

$(OBJ_DIR)/lig4.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/Lig4.hpp $(SRC_DIR)/Lig4.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Lig4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/lig4.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Reversi.hpp $(INCLUDE_DIR)/JogodaVelha.hpp $(INCLUDE_DIR)/Lig4.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/jogador.o $(OBJ_DIR)/jogos.o $(OBJ_DIR)/reversi.o $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/lig4.o 
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/jogador.o $(OBJ_DIR)/jogos.o $(OBJ_DIR)/reversi.o $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/lig4.o -o main

clean:
	rm -f main $(OBJ_DIR)/*.o