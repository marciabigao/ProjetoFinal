#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <map>

class Jogador
{
    private:
    std::string nome_jogador;
    std::string apelido_jogador;

    int vitorias_reversi, derrotas_reversi;
    int vitorias_lig, derrotas_lig;
    int vitorias_jvelha, derrotas_jvelha;
    
    static std::map<std::string, Jogador*> jogadores;

    public:
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int vr, int dr, int vl, int dl, int vjv, int djv);
    ~Jogador();

    void cadastra_jogador(std::string nome, std::string apelido);
    void remove_jogador(std::string apelido);
    void imprime_listagem(char opcao);
    void le_estatisticas();
    void atualiza_estatisticas();
    Jogador* busca_jogador(std::string apelido);
    void apaga_map();
    void registrar_vitoria(std::string apelido, char jogo);
    void registrar_derrota(std::string apelido, char jogo);

    std::string get_nome();
    std::string get_apelido();
    int get_vitorias_r();
    int get_derrotas_r();
    int get_vitorias_lig();
    int get_derrotas_lig();
    int get_vitorias_jv();
    int get_derrotas_jv();
};
#endif