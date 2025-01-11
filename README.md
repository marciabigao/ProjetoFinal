# tp-pds2
Trabalho Final de PDSII


**Izabela (versão informal e com erros!!)**

Primeiramente li as instruções do trabalho prático para o jogo que fiquei encarregada, o jogo da velha, tendo em vista que as classes Jogador e Jogos (classes mãe), já estavam prontas.
Assim, delimitei o que o meu jogo deveria conter:

1- entrada e mensagens para jogadas inválidas
Jogada no Jogo da Velha
<Linha> <Coluna>
ERRO: formato incorreto
ERRO: jogada inválida

2- Tratamento de excessões

3- Impressão do tabuleiro a cada jogada 

Agora, vamos definir os elementos componentes/regras do jogo:
2 jogadores
2 símbolos (X e O)
tabuleiro com 9 espaços
ganha quem completar 3 símbolos seguidos, quer seja na horizontal, vertical, ou até mesmo na diagonal
símbolos não podem colocados por cima de outros
se nenhum jogador alcançar o objetivo, popularmente falamos que "deu velha" 

Aparentemente, o jogo é bem simples de ser implementado, então vamos partir para o código

1- JogodaVelha.hpp
Vamos detalhar nesse tópico, o que foi feito no header (cabeçalho ou .hpp) do jogo da velha.
Primeiramente, incluo as classes que utilizarei nessa subclasse, definidas pelos colegas: Jogador.hpp e Jogo.hpp
Já que o Jogo da Velha é um (is_a) jogo, defini ele herdando no método public, a classe jogos.
Defini o atributo char do jogador atual (X ou O) e reescrivi métodos da classe mãe com override e adicionei novos métodos.

2- JogodaVelha.cpp

--construtor e destrutor
Defino o construtor como um tabuleiro 3x3 e o primeiro jogador, por padrão, como o X

--método testarValidade
Agora, partindo para o método sobreescrito que testa a validade. Aqui, encontrei uma dificuldade. Na classe base, o parâmtro valor é passado para o método. Contudo, no jogo da velha, esse parâmetro não é necessário para testar a válidade, já que os valores (X e O) são alterados automaticamente a cada jogada, justamente com o novo método criado, alternar jogador.
Para não ter de mudar a classe base, afetando outros jogos, apenas não usarei esse parâmetros, mesmo ele estando na assinatura do método.

Esse método apenas testa se a posição inserida, tanto das linhas, como das colunas, está entre 0 e 2, já que defini meu tabuleiro assim.

--método testarVitoria
Esse método também foi sobreescrito da classe Jogos. Ele é bem simples. Primeiro faz um loop que verifica se o jogador atual (X ou O) ganhou na horizontal e vertical, e depois verifica as diagonais.

--método testarEmpate
Esse novo método (outros jogos podem não possuir empate), definido para o jogo da velha, testa se todas as posições foram preenchidas, dado que antes a função testarVitoria é chamada. Se não houve vitória e todas as casas foram preenchidas, o jogo terminou em empate 

--método executarJogada
Esse método verifica se a jogada é válida e, se for, modifica o tabuleiro conforme a linha e coluna inserida pelo usuário. Se a jogada não for válida, imprime uma mensagem de erro, como pedida no enunciado do tp

--método imprimirTabuleiro
Esse método também foi sobreescrito. Ele faz um loop e verifica se cada posição está vazia. Se estiver, imprime um ponto seguido de um espaço. Se não estiver, imprime o caractére seguido de espaço.

MÁRCIA
reversi:
A primeira dificuldade foi em aprender o jogo, porque ele é complexo e ninguém do grupo o conhecia. A refedinição dos métodos virtuais foi bem tranquila, mas oq ue me deu mais trabalho em toda a implementação foi a função testarValidade, porque o tabuleiro do jogo é muito grande e você tem que fazer verificações nas linhas, colunas e diagonais, averiguando se nesses sentidos tem uma peça da mesma cor da que você está querendo colocar, depois ver se não existem espaços vazios entre ela e se existe pelo menos uma peça da outra cor. Mas, depois que essa função foi resolvida, a sua lógia pode ser aplicada em outras (como o verificar vitoria e o inverter simbolos), facilitando o processo. Tive que adicionar tres metodos (inverterSimbolos, declararVencedor e existeJogadaValida) que eram necessárias para as regras do jogo.

fluxo:
A maior dificuldade foi, primeiro, entender o código que o pessoal tinha feito. Cada jogo é diferente e cada um tem a sua abordagem, então esse foi um processo. O fluxo em si foi muito tranquilo, mas o que consumiu tempo foi padronizar as implementações dos jogos. Por exemplo, no meio do caminho percebi que os jogos tinham implementados métodos com a mesma finalidade e que não estavam na classe abstrata, então tive que mudar isso. Vi que alguns métodos estavam fazendo coisas que eram do fluxo, e tive que mudar também. Vi que um dos jogos estava diferente quanto à implementação das vezes nos jogadores e dessa alternância, então tive que mudar. A maior dificuldade foram amis esses conflitos mesmo, o resto foi bem tranquilo.


