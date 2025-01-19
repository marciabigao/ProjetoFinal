#include "../include/Jogador.hpp"
#include "../include/Reversi.hpp"
#include "../include/JogodaVelha.hpp"
#include "../include/Lig4.hpp"
#include "../include/Erros.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

int main() {
    try
    {
        Jogador::leEstatisticas();
    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
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
            try 
            {
                std::string apelido, nome;
                std::cin >> apelido;
                std::getline(std::cin, nome);
                nome.erase(0,1);
 
                Jogador* novoJogador = new Jogador(nome, apelido);
                novoJogador->cadastraJogador(apelido);
            }
            catch(ExcecaoJogadorRepetido& e)
            {
                std::cout << e.what() <<std::endl;
            }
        }
        else if(operacao == "RJ")
        {   
            try
            {
                std::string apelido;
                std::cin >> apelido;
                Jogador* JogadorASerRemovido = Jogador::buscaJogador(apelido);
                JogadorASerRemovido->removeJogador(apelido);
            }
            catch(const ExcecaoJogadorInexistente& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if(operacao == "LJ")
        {
            try
            {
                char opcaoListagem;
                std::cin >> opcaoListagem;

                if(opcaoListagem != 'A' && opcaoListagem != 'N')
                {
                    throw std::invalid_argument("Erro: entrada inválida");
                }

                Jogador::imprimeListagem(opcaoListagem);
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << std::endl;
            }
                
        }
        else if(operacao == "EP")
        {
            try
            {
                char jogo;
                std::string apelidoJogador1, apelidoJogador2;
                std::cin >> jogo;

                if(jogo != 'R' && jogo != 'L' && jogo != 'V')
                {
                    throw std::invalid_argument("ERRO: dados incorretos");
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
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << std::endl;
            }
            catch (const ExcecaoJogadorInexistente& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if(operacao == "FS")
        {
            try
            {
                Jogador::atualizaEstatisticas();
                Jogador::apagaMap();
            }
            catch(const std::ios_base::failure& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }

    } while (operacao != "FS");

    return 0;
}