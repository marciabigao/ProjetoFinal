#include "../include/Jogador.hpp"
#include "../include/Reversi.hpp"
#include "../include/JogodaVelha.hpp"
#include "../include/Lig4.hpp"
#include <iostream>
#include <string>
#include <sstream>

bool temMaisdeUmaPalavra(std::string string);

int main() {

    Jogador::leEstatisticas();
    std::string operacao;

    std::cout << "Escolha entre os comandos abaixo:" << std::endl;
    std::cout << "CJ <Apelido> <Nome>: Cadastrar Jogador" << std::endl;
    std::cout << "RJ <Apelido>: Remover Jogador" << std::endl;
    std::cout << "LJ <N/A>: Listar Jogadores (por nome ou apelido)" << std::endl;
    std::cout << "EP <R/L/V> <Apelido Jogador 1> <Apelido Jogador 2>: Executar Partida" << std::endl;
    std::cout << "FS: Finalizar Sistema" << std::endl;

    do
    {
        std::cin >> operacao;

        if(operacao == "CJ")
        {
            std::string apelido, nome;
            std::cin >> apelido;
            std::getline(std::cin, nome);
            nome.erase(0,1);
            
            Jogador* novoJogador = new Jogador(nome, apelido);
            novoJogador->cadastraJogador(apelido);
            novoJogador->atualizaEstatisticas();
        }
        else if(operacao == "RJ")
        {
            std::string apelido;
            std::cin >> apelido;

            Jogador* JogadorASerRemovido = Jogador::buscaJogador(apelido);
            JogadorASerRemovido->removeJogador(apelido);
            JogadorASerRemovido->atualizaEstatisticas();
        }
        else if(operacao == "LJ")
        {
            char opcaoListagem;
            std::cin >> opcaoListagem;

            if(opcaoListagem != 'A' && opcaoListagem != 'N')
            {
                std::cout << "Erro: entrada inválida" << std::endl; 
            }

            Jogador::imprimeListagem(opcaoListagem);
        }
        else if(operacao == "EP")
        {
            char jogo;
            std::string apelidoJogador1, apelidoJogador2;
            std::cin >> jogo;

            if(jogo != 'R' && jogo != 'L' && jogo != 'V')
            {
                std::cout << "ERRO: dados incorretos" << std::endl;
            }

            std::cin >> apelidoJogador1;
            std::cin >> apelidoJogador2;

            Jogador* jogador1 = Jogador::buscaJogador(apelidoJogador1);
            Jogador* jogador2 = Jogador::buscaJogador(apelidoJogador2);

            if(jogo == 'R')
            {
                std::cout << "Reversi" << std::endl;
                Reversi reversi;
                reversi.executarPartida(jogador1, jogador2);
            }
            else if(jogo == 'L')
            {
                std::cout << "Lig4" << std::endl;
                std::cout << "Indique as dimensões do tabuleiro:" << std::endl;
	            int numeroLinhas, numeroColunas;
	            std::cout << "Número de linhas: ";
	            std::cin >> numeroLinhas;
	            std::cout << "Número de colunas: ";
	            std::cin >> numeroColunas;
	            std::cout << std::endl;

	            Lig4 lig4(numeroLinhas, numeroColunas);
                lig4.executarPartida(jogador1, jogador2);

            }
            else if(jogo == 'V')
            {
                std::cout << "Jogo da Velha" << std::endl;
                JogoDaVelha jogoDaVelha;
                jogoDaVelha.executarPartida(jogador1, jogador2);
            }
        }
        else if(operacao == "FS")
        {
            Jogador::apagaMap();
        }

    } while (operacao != "FS");

    return 0;
}

bool temMaisdeUmaPalavra(std::string string)
{
    std::stringstream str(string);
    std::string palavra;
    int contador;

    while(str >> palavra)
    {
        contador++;
    }

    return (contador > 1);
}