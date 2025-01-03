#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <map>

class Jogador
{
    private:
    std::string nomeJogador;
    std::string apelidoJogador;

    int vitoriasReversi, derrotasReversi;
    int vitoriasLig, derrotasLig;
    int vitoriasJVelha, derrotasJVelha;
    
    static std::map<std::string, Jogador*> jogadores;

    public:
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int vr, int dr, int vl, int dl, int vjv, int djv);

    static void imprimeListagem(char opcao);
    static void leEstatisticas();
    static void atualizaEstatisticas();
    static Jogador* buscaJogador(std::string apelido);
    static void apagaMap();
    void cadastraJogador(std::string apelido);
    void removeJogador(std::string apelido);
    void registrarVitoria(std::string apelidoVencedor, char jogo);
    void registrarDerrota(std::string apelidoPerdedor, char jogo);

    std::string getNome();
    std::string getApelido();
    int getVitoriasR();
    int getDerrotasR();
    int getVitoriasLig();
    int getDerrotasLig();
    int getVitoriasJV();
    int getDerrotasJV();
};
#endif