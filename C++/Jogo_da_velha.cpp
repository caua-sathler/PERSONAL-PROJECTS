#include <iostream>
#include <ctime>

void gerar_tabuleiro(std::string tab[][3]) { //função responsável pela criação do tabuleiro do jogo. O tabuleiro contém as coordenadas de cada cédula para ajudar o jogador.
    std::cout << "************************\n";
    std::cout << " (1 1) | (1 2) | (1 3)  " << '\n';
    std::cout << "  " << tab[0][0] << "  |  " << tab[0][1] << "  |  " << tab[0][2] << "  " << '\n';
    std::cout << "       |       |     " << '\n';
    std::cout << "-----------------------" << '\n';
    std::cout << " (2 1) | (2 2) | (2 3)  " << '\n';
    std::cout << "  " << tab[1][0] << "  |  " << tab[1][1] << "  |  " << tab[1][2] << "  " << '\n';
    std::cout << "       |       |     " << '\n';
    std::cout << "-----------------------" << '\n';
    std::cout << " (3 1) | (3 2) | (3 3)  " << '\n';
    std::cout << "  " << tab[2][0] << "  |  " << tab[2][1] << "  |  " << tab[2][2] << "  " << '\n';
    std::cout << "       |       |     " << '\n';
    std::cout << "************************\n";
}

void movimento_jogador(std::string tab[][3], int &x, int &y, std::string w) { //função responsável pela jogada do jogador.
    do {
        std::cout << "Digite as coordenadas da sua jogada no formato (X Y)!\n";
        std::cin >> x >> y;
        x -= 1; //o jogador digita a coordenada e elas são subtraídas em 1 para se encaixar na lógica das arrays.
        y -= 1;
    } while((x < 0) || (x > 2) || (y < 0) || (y > 2) || tab[x][y] != "   "); //condição do while impede que o jogador digite uma cédula fora do tabuleiro ou que já esteja ocupada.
       
    tab[x][y] = w;
    gerar_tabuleiro(tab); //caso esteja tudo ok, o jogador faz sua jogada e o tabuleiro é atualizado.
}

void movimento_computador(std::string tab[][3], std::string w) { //função responsável pelos movimentos do computador.
    int x, y;
    srand(time(0)); //seed para criar números aleatórios.

    do {
        x = rand() % 3;
        y = rand() % 3; //cria números aleatórios dentro das dimensões do tabuleiro. Repete esse processo até encontrar uma cédula que esteja vazia.
    } while(tab[x][y] != "   ");

    tab[x][y] = w; //atualiza o tabuleiro com a jogada do computador.

    std::cout << "Pressione Enter para o computador executar sua jogada.\n"; //aguarda o jogador pressionar uma tecla para dar continuidade ao programa. Adicionei para facilitar a vizualização.
    std::cin.ignore(); 
    std::cin.get();
    std::cout << "Tabuleiro após a jogada do computador:\n";
    gerar_tabuleiro(tab); //exibe o tabuleiro após a jogada do computador.
}

bool vitoria(std::string tab[][3], std::string simbolo) { //função que verifica se houve vitória de alguma das partes.
    for (int i = 0; i < 3; ++i) { 
        //chegagem das linhas e colunas.
        if ((tab[i][0] == simbolo && tab[i][1] == tab[i][0] && tab[i][2] == tab[i][0]) || 
            (tab[0][i] == simbolo && tab[1][i] == tab[0][i] && tab[2][i] == tab[0][i])) {
            return true;
        }
    }
        //chegagem das diagonais.
        if ((tab[0][0] == simbolo && tab[1][1] == tab[0][0] && tab[2][2] == tab[0][0]) || 
        (tab[0][2] == simbolo && tab[1][1] == tab[0][2] && tab[2][0] == tab[0][2])) {
        return true;
    }
    return false;
}

bool em_andamento(std::string tab[][3], std::string simbolo_jogador, std::string simbolo_pc) { //função que verifica se o jogo ainda está em andamento.
    if(vitoria(tab, simbolo_jogador)) {
        std::cout << "PARABENS! VOCÊ VENCEU!\n"; 
        return false; //caso o jogador vença, o jogo é interrompido e é exibido a mensagem.
    }
    if(vitoria(tab, simbolo_pc)) {
        std::cout << "VOCE PERDEU.\n";        
        return false; //caso o computador vença, o jogo é interrompido e é exibido a mensagem.
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tab[i][j] == "   ") return true; //caso ainda haja cédulas vazias, o jogo permanece rodando.
        }
    }

    std::cout << "EMPATE.\n"; //caso ninguém ganhe e não haja mais espaços vazios, há um empate.
    return false;
}

std::string conversor_char_string(char y) { //função responsável por converter o caracter a ser jogado em uma string nas dimensões corretas para se centralizar em cada cédula do tabuleiro.
    return std::string(" ") + y + " ";
}

int main() {
    char controle = ' ';
    char simb_jogador;
    char simb_pc;
    std::cout << "BEM-VINDO AO JOGO DA VELHA!\n";

    do {
        std::cout << "Pressione 'J' para jogar e 'S' para sair!\n"; //comando de controle
        std::cin >> controle; 
        controle = toupper(controle);
    } while (controle != 'J' && controle != 'S');

    if (controle == 'S') {
        std::cout << "Voce saiu! Volte sempre!\n";
        return 0;
    }

    std::cout << "Escolha seu simbolo: 'X' ou 'O'? ";
    do {
        std::cin >> simb_jogador;
        simb_jogador = toupper(simb_jogador);
    } while (simb_jogador != 'X' && simb_jogador != 'O'); //jogador escolhe o seu símbolo

    std::string escolhaDoJogador = conversor_char_string(simb_jogador); //símbolo do jogador é convertido em uma string com dimensões adequadas

    if(simb_jogador == 'X') simb_pc = 'O';
    else simb_pc = 'X'; //define o símbolo do computador como o símbolo que o jogador não escolheu

    std::string pc = conversor_char_string(simb_pc); //símbolo do computador é convertido

    while(controle == 'J') { //caso o jogador tenha pressionado 'J' o jogo têm inicio. Enquanto controle permanecer igual a 'J' o jogo irá se repetir
        std::string tabuleiro[3][3] = {{"   ", "   ", "   "},
                                       {"   ", "   ", "   "},
                                       {"   ", "   ", "   "}};
        int mov_playerX, mov_playerY;

        std::cout << "Veja o tabuleiro que voce ira jogar!\n";
        gerar_tabuleiro(tabuleiro);
        while(em_andamento(tabuleiro, escolhaDoJogador, pc)) { //loop que gerencia o jogo com base no valor da função em_andamento
            movimento_jogador(tabuleiro, mov_playerX, mov_playerY, escolhaDoJogador);
            if (!em_andamento(tabuleiro, escolhaDoJogador, pc)) break;
            movimento_computador(tabuleiro, pc);
        }

        do {
            std::cout << "Pressione 'J' para jogar novamente ou 'S' para sair.\n"; //após o jogo finalizar, o jogador pode escolher jogar novamente ou sair.
            std::cin >> controle;
            controle = toupper(controle);
        } while (controle != 'J' && controle != 'S');
    }

    std::cout << "Voce saiu! Volte sempre!\n";
    return 0;
}
