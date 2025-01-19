CC = g++
CFLAGS = -std=c++11 -Wall

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
TESTS_DIR = tests

all:main tests

#Objetos Main

$(OBJ_DIR)/jogador.o: $(INCLUDE_DIR)/Jogador.hpp $(SRC_DIR)/Jogador.cpp $(INCLUDE_DIR)/Erros.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogador.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/jogador.o

$(OBJ_DIR)/jogos.o: $(INCLUDE_DIR)/Jogos.hpp $(SRC_DIR)/Jogos.cpp $(INCLUDE_DIR)/Erros.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogos.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/jogos.o

$(OBJ_DIR)/reversi.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/Reversi.hpp $(SRC_DIR)/Reversi.cpp $(INCLUDE_DIR)/Erros.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/reversi.o

$(OBJ_DIR)/jogodavelha.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/JogodaVelha.hpp $(SRC_DIR)/JogodaVelha.cpp $(INCLUDE_DIR)/Erros.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/JogodaVelha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/jogodavelha.o

$(OBJ_DIR)/lig4.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/Lig4.hpp $(SRC_DIR)/Lig4.cpp $(INCLUDE_DIR)/Erros.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Lig4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/lig4.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Reversi.hpp $(INCLUDE_DIR)/JogodaVelha.hpp $(INCLUDE_DIR)/Lig4.hpp $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/Erros.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

#Objetos Testes
$(OBJ_DIR)/teste_jogador.o: $(INCLUDE_DIR)/doctest.h $(INCLUDE_DIR)/Jogador.hpp $(TESTS_DIR)/teste_Jogador.cpp
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/teste_Jogador.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/teste_jogador.o

$(OBJ_DIR)/teste_jogos.o: $(INCLUDE_DIR)/doctest.h $(INCLUDE_DIR)/Jogos.hpp $(TESTS_DIR)/teste_Jogos.cpp
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/teste_Jogos.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/teste_jogos.o

$(OBJ_DIR)/teste_reversi.o: $(INCLUDE_DIR)/doctest.h $(INCLUDE_DIR)/Jogador.hpp  $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/Reversi.hpp $(TESTS_DIR)/teste_Reversi.cpp
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/teste_Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/teste_reversi.o

$(OBJ_DIR)/teste_jogodavelha.o: $(INCLUDE_DIR)/doctest.h $(INCLUDE_DIR)/Jogador.hpp  $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/JogodaVelha.hpp $(TESTS_DIR)/teste_JogodaVelha.cpp
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/teste_JogodaVelha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/teste_jogodavelha.o

$(OBJ_DIR)/teste_lig4.o: $(INCLUDE_DIR)/doctest.h $(INCLUDE_DIR)/Jogador.hpp  $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/Lig4.hpp $(TESTS_DIR)/teste_Lig4.cpp
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/teste_Lig4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/teste_lig4.o


main: $(OBJ_DIR)/main.o $(OBJ_DIR)/jogador.o $(OBJ_DIR)/jogos.o $(OBJ_DIR)/reversi.o $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/lig4.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/jogador.o $(OBJ_DIR)/jogos.o $(OBJ_DIR)/reversi.o $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/lig4.o -o main

tests: $(OBJ_DIR)/jogador.o $(OBJ_DIR)/jogos.o $(OBJ_DIR)/reversi.o $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/lig4.o \
 		$(OBJ_DIR)/teste_jogador.o $(OBJ_DIR)/teste_jogos.o $(OBJ_DIR)/teste_reversi.o $(OBJ_DIR)/teste_jogodavelha.o $(OBJ_DIR)/teste_lig4.o
		
		$(CC) $(CFLAGS) $(OBJ_DIR)/jogador.o $(OBJ_DIR)/jogos.o $(OBJ_DIR)/reversi.o $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/lig4.o \
		$(OBJ_DIR)/teste_jogador.o $(OBJ_DIR)/teste_jogos.o $(OBJ_DIR)/teste_reversi.o $(OBJ_DIR)/teste_jogodavelha.o $(OBJ_DIR)/teste_lig4.o -o testes
	
clean:
	rm -f main testes $(OBJ_DIR)/*.o

run: main
	./main

run_tests: tests
	./testes