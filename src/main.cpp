#include "../include/Jogador.hpp"
#include "../include/Reversi.hpp"
#include "../include/JogodaVelha.hpp"
#include "../include/Lig4.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main() {

    Jogador::leEstatisticas();
    std::string operacao;

    do
    {
        std::cin >> operacao;

        if(operacao == "CJ")
        {
            std::string apelido, nome;
            std::getline(std::cin, apelido);
            std::getline(std::cin, nome);

            if(temMaisdeUmaPalavra(apelido))
            {
                std::cout << "ERRO: dados incorretos" << std::endl;
            }

            Jogador* novoJogador = new Jogador(nome, apelido);
            novoJogador->cadastraJogador(apelido);
        }
        else if(operacao == "RJ")
        {
            std::string apelido;
            std::cin >> apelido;

            Jogador* JogadorASerRemovido = Jogador::buscaJogador(apelido);
            JogadorASerRemovido->removeJogador(apelido);
        }
        else if(operacao == "LJ")
        {
            char opcaoListagem;
            std::cin >> opcaoListagem;

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

            std::getline(std::cin, apelidoJogador1);
            std::getline(std::cin, apelidoJogador2);

            if(temMaisdeUmaPalavra(apelidoJogador1) || temMaisdeUmaPalavra(apelidoJogador2))
            {
                std::cout << "ERRO: dados incorretos" << std::endl;
            }

            Jogador* jogador1 = Jogador::buscaJogador(apelidoJogador1);
            Jogador* jogador2 = Jogador::buscaJogador(apelidoJogador2);

            if(jogo == 'R')
            {

            }
            else if(jogo == 'L')
            {

            }
            else if(jogo == 'V')
            {
                
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