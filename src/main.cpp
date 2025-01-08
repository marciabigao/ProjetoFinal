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

        }
        else if(operacao == "EP")
        {

        }
        else if(operacao == "FS")
        {

        }

    } while (operacao != "FS");
    
    Jogador::apagaMap();

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