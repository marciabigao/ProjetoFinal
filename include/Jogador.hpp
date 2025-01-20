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

    struct comparaMap
    {
        bool operator()(const std::string& a, const std::string& b) const
        {
            std::string lowerA = a;
            std::string lowerB = b;

            for(char& c : lowerA)
            {
                c = std::tolower(c);
            }
            for(char& c : lowerB)
            {
                c = std::tolower(c);
            }
            if (lowerA < lowerB) return true;
            if (lowerA > lowerB) return false;
            return a < b;
        }
    };
    
    static std::map<std::string, Jogador*, comparaMap> jogadores;

    public:
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int vr, int dr, int vl, int dl, int vjv, int djv);

    static void imprimeListagem(char opcao);
    static void leEstatisticas();
    static void atualizaEstatisticas();
    static Jogador* buscaJogador(std::string apelido);
    static void apagaMap();
    static bool comparaSort(Jogador* a, Jogador*b);
    void cadastraJogador(std::string apelido);
    void removeJogador(std::string apelido);
    void registrarVitoria(char jogo);
    void registrarDerrota(char jogo);

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