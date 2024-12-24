#include "Jogador.hpp"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::map<std::string, Jogador*> Jogador::jogadores;

std::string Jogador::get_nome()
{
    return this->nome_jogador;
}

std::string Jogador::get_apelido()
{
    return this->apelido_jogador;
}

int Jogador::get_vitorias_r()
{
    return this->vitorias_reversi;
}

int Jogador::get_derrotas_r()
{
    return this->derrotas_reversi;
}

int Jogador::get_vitorias_lig()
{
    return this->vitorias_lig;
}

int Jogador::get_derrotas_lig()
{
    return this->derrotas_lig;
}

int Jogador::get_vitorias_jv()
{
    return this->vitorias_jvelha;
}

int Jogador::get_derrotas_jv()
{
    return this->derrotas_jvelha;
}

Jogador::Jogador(std::string nome, std::string apelido)
{
    this->nome_jogador = nome;
    this->apelido_jogador = apelido;

    this->vitorias_reversi = 0;
    this->derrotas_reversi = 0;

    this->vitorias_lig = 0;
    this->derrotas_lig = 0;

    this->vitorias_jvelha = 0;
    this->derrotas_jvelha = 0;
}

void Jogador::cadastra_jogador(std::string nome, std::string apelido)
{
    //se o apeldio buscado não estiver no map, retorna end (próxima posição vazia)
    if(jogadores.find(apelido) != jogadores.end())
    {
        std::cout << "ERRO: jogador repetido" << std::endl;
    }
    else
    {
        Jogador *novo_jogador = new Jogador(nome, apelido);
        jogadores.insert({apelido, novo_jogador});
        std::cout << "Jogador " << apelido << " inserido com sucesso" << std::endl;
    }
}

void Jogador::remove_jogador(std::string apelido)
{
    if(jogadores.find(apelido) == jogadores.end())
    {
        std::cout << "ERRO: jogador inexistente" << std::endl;
    }
    else
    {
        jogadores.erase(apelido);
        std::cout << "Jogador " << apelido << " removido com sucesso" <<std::endl;
    }
}