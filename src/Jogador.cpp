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
