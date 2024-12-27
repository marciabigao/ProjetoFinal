#include "Jogador.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
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

Jogador::Jogador(std::string nome, std::string apelido):
         nome_jogador(nome), apelido_jogador(apelido),
         vitorias_reversi(0), derrotas_reversi(0),
         vitorias_lig(0), derrotas_lig(0),
         vitorias_jvelha(0), derrotas_jvelha(0) {}

Jogador::Jogador(std::string nome, std::string apelido, int vr, int dr,
                 int vl, int dl, int vjv, int djv):
         nome_jogador(nome), apelido_jogador(apelido),
         vitorias_reversi(vr), derrotas_reversi(dr),
         vitorias_lig(vl), derrotas_lig(dl),
         vitorias_jvelha(vjv), derrotas_jvelha(djv) {}        

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
    auto iterador = jogadores.find(apelido);
    if(iterador == jogadores.end())
    {
        std::cout << "ERRO: jogador inexistente" << std::endl;
    }
    else
    {
        //libera a memória previamente alocada
        delete iterador->second;
        //apaga o par do mapa
        jogadores.erase(apelido);
        std::cout << "Jogador " << apelido << " removido com sucesso" <<std::endl;
    }
}

void Jogador::atualiza_estatisticas()
{
    std::ofstream saida("estatisticas.txt", std::fstream :: out);
    if(!saida.is_open())
    {
        std::cout << "ERRO: falha ao abrir o aqruivo de saída" << std::endl;
        return;
    }

    for(std::pair<const std::string, Jogador*>& player : jogadores)
    {
        saida << player.second->nome_jogador << " " << player.second->apelido_jogador << " "
              << player.second->vitorias_reversi << " " << player.second->derrotas_reversi << " "
              << player.second->vitorias_lig << " " << player.second->derrotas_lig << " "
              << player.second->vitorias_jvelha << " " << player.second->derrotas_jvelha << " "
              << std::endl;
    }
    saida.close();
}

//Método a ser utilizado no início de uma nova execução para recuperar 
//as informações de partidas anteriores armazenadas no arquivo, inserindo-as no map
void Jogador::le_estatisticas()
{
    std::ifstream entrada("estatisticas.txt", std::fstream :: in);
    if(!entrada.is_open())
    {
        std::cout << "ERRO: falha ao abrir o arquivo de entrada" << std::endl;
        return;
    }
    std::string dados;
    std::string nome, apelido;
    int vr, dr, vl, dl, vjv, djv;
    while(std::getline(entrada, dados))
    {
        std::istringstream info_lida(dados);
        if(!(info_lida >> nome))
        {
            std::cout << "ERRO: nome não foi lido com sucesso" << std::endl;
            return;
        }
        if(!(info_lida >> apelido))
        {
            std::cout << "ERRO: apelido não foi lido com sucesso" << std::endl;
            return;
        }
        if(!(info_lida >> vr >> dr >> vl >> dl >> vjv >> djv))
        {
            std::cout << "ERRO: dados numéricos não foram lidos com sucesso" << std::endl;
            return;
        }
        Jogador* jogador_inserido = new Jogador(nome, apelido, vr, dr, vl, dl, vjv, djv);
        jogadores.insert({apelido, jogador_inserido});
    }
    entrada.close();
}

void Jogador::imprime_listagem(char opcao)
{
    if(opcao == 'A')
    {
        for(std::pair<const std::string, Jogador*>& player : jogadores)
        {
            std::cout << player.first << " " << player.second->get_nome() << std::endl;

            std::cout << "REVERSI - V: " << player.second->get_vitorias_r() 
                      << " D: " << player.second->get_derrotas_r() << std::endl;

            std::cout << "LIG4 - V: " << player.second->get_vitorias_lig()
                      << " D: " << player.second->get_derrotas_lig() << std::endl;

            std::cout << "VELHA - V: " << player.second->get_vitorias_jv()
                      << " D: " << player.second->get_vitorias_jv() << std::endl;
        }
    }

    else if(opcao == 'N')
    {
        std::vector <Jogador*> vetor;
        for(std::pair<const std::string, Jogador*>& player : jogadores)
        {
            //copia os dados do map para um vector
            vetor.push_back(player.second);
        }
        //utiliza o algoritmo sort com uma função lambda personalizada para
        //ordenar os dados em função do atributo nome_jogador dos jogadores
        std::sort(vetor.begin(), vetor.end(),
        [](Jogador* jogador_a, Jogador* jogador_b)
        {
            return jogador_a->get_nome() < jogador_b->get_nome();
        });

        for(Jogador* player : vetor)
        {
            std::cout << player->get_apelido() << " " << player->get_nome() << std::endl;

            std::cout << "REVERSI - V: " << player->get_vitorias_r() 
                      << " D: " << player->get_derrotas_r() << std::endl;

            std::cout << "LIG4 - V: " << player->get_vitorias_lig()
                      << " D: " << player->get_derrotas_lig() << std::endl;

            std::cout << "VELHA - V: " << player->get_vitorias_jv()
                      << " D: " << player->get_vitorias_jv() << std::endl;
        }
    }
}