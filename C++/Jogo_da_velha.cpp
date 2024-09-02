#include <iostream>
#include <ctime>

void gerar_tabuleiro(std::string tab[][3]){
    std::cout << "************************\n";
    std::cout << " (1 1) |" << " (1 2) |" << " (1 3)  " << '\n';
    std::cout << "  " << tab[0][0] << "  |" << "  " << tab[0][1] << "  |" << "  " << tab[0][2] << "  " << '\n';
    std::cout << "       |       |     " << '\n';
    std::cout << "-----------------------" << '\n';
    std::cout << " (2 1) |" << " (2 2) |" << " (2 3)  " << '\n';
    std::cout << "  " << tab[1][0] << "  |" << "  " << tab[1][1] << "  |" << "  " << tab[1][2] << "  " << '\n';
    std::cout << "       |       |     " << '\n';
    std::cout << "-----------------------" << '\n';
    std::cout << " (3 1) |" << " (3 2) |" << " (3 3)  " << '\n';
    std::cout << "  " << tab[2][0] << "  |" << "  " << tab[2][1] << "  |" << "  " << tab[2][2] << "  " << '\n';
    std::cout << "       |       |     " << '\n';
    std::cout << "************************\n";
}

void movimento_jogador(std::string tab[][3], int &x, int &y){
    do {
        std::cout << "Digite as coordenadas da sua jogada no formato (X Y)!\n";
        std::cin >> x >> y;
        x -= 1;
        y -= 1;
    } while((x < 0) || (x > 2) || (y < 0) || tab[x][y] != "   ");
       
    tab[x][y] = " X ";
    
    gerar_tabuleiro(tab);
}

void movimento_computador(std::string tab[][3], int &x, int &y){
    srand(time(NULL));
    
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while(tab[x][y] != "   ");

    tab[x][y] = " O ";

    gerar_tabuleiro(tab);
}

bool vitoria(std::string tab[][3], std::string simbolo){
    for (int i = 0; i < 3; ++i) {
        if ((tab[i][0] == simbolo && tab[i][1] == tab[i][0] && tab[i][2] == tab[i][0]) || 
            (tab[0][i] == simbolo && tab[1][i] == tab[0][i] && tab[2][i] == tab[0][i])) {
            return true;
        }
    }
    if ((tab[0][0] == simbolo && tab[1][1] == tab[0][0] && tab[2][2] == tab[0][0]) || 
        (tab[0][2] == simbolo && tab[1][1] == tab[0][2] && tab[2][0] == tab[0][2])) {
        return true;
    }
    return false;
}

bool em_andamento(std::string tab[][3], char &controle){
   if(vitoria(tab, " X ")) {
       std::cout << "PARABENS! VOCE VENCEU!\n"; 
       return false;
   }
   if(vitoria(tab, " O ")) {
       std::cout << "VOCE PERDEU.\n";        
       return false;
   }
   for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tab[i][j] == "   ") return true;
        }
    }

    std::cout << "EMPATE.\n";
    return false;
}

int main(){
    char controle = ' ';
    std::cout << "BEM-VINDO AO JOGO DA VELHA!\n";

    do {
        std::cout << "Pressione 'J' para jogar e 'S' para sair!\n";
        std::cin >> controle; 
        controle = toupper(controle);
    } while (controle != 'J' && controle != 'S');

    while(controle == 'J'){
        std::string tabuleiro[3][3] = {{"   ", "   ", "   "},
                                       {"   ", "   ", "   "},
                                       {"   ", "   ", "   "}};
        int mov_playerX, mov_playerY;
        int mov_pcX, mov_pcY;

        std::cout << "Veja o tabuleiro que voce ira jogar!\n";
        while(em_andamento(tabuleiro, controle)){
            gerar_tabuleiro(tabuleiro);
            movimento_jogador(tabuleiro, mov_playerX, mov_playerY);
            if (!em_andamento(tabuleiro, controle)) break;
            movimento_computador(tabuleiro, mov_pcX, mov_pcY);
            if (!em_andamento(tabuleiro, controle)) break;
     }


        do {
            std::cout << "Pressione 'J' para jogar novamente ou 'S' para sair.\n";
            std::cin >> controle;
            controle = toupper(controle);
        } while (controle != 'J' && controle != 'S');
    }
    
    std::cout << "Voce saiu! Obrigado pela presença!\n";
    return 0;
}
