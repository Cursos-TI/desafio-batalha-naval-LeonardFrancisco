#define MAR 0
#define TAMANHONAVIO 3
#define NAVIO 3

#include <stdio.h>

//Função pra verificar se os navios não se sobrepõem.
int verificarPosicao(int tabuleiro[10][10], int linha, int coluna, char direcao){
    for (int i = 0; i < TAMANHONAVIO; i++){
        if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10 || tabuleiro[linha][coluna] == NAVIO){
            return 0;
        }

        //Ajusta as coordenadas para fazer a verificação completa.
        if (direcao == 'H' || direcao == 'h'){
            coluna++;
        } else if (direcao == 'V' || direcao == 'v'){
            linha++;
        } else if (direcao == 'C' || direcao == 'c'){
            linha--;
            coluna++;
        } else if (direcao == 'D' || direcao == 'd'){
            linha++;
            coluna++;
        }
    }

    return 1;
}


// Procedimento para poder posicionar os navioss.
void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, char direcao){
    if (verificarPosicao(tabuleiro, linha, coluna, direcao)){
        for (int i = 0; i < TAMANHONAVIO; i++){
            tabuleiro[linha][coluna] = NAVIO;
            
            //Verifica a direçao.
            if (direcao == 'H' || direcao == 'h'){
                coluna++;
            } else if (direcao == 'V' || direcao == 'v'){
                linha++;
            } else if (direcao == 'C' || direcao == 'c'){
                linha--;
                coluna++;
            } else if (direcao == 'D' || direcao == 'd'){
                linha++;
                coluna++;
            } else{
                printf("Direção inválida!");
            }
        }
    } else{
        printf("Posição já preenchida ou inexistente! Escolha outra!\n");
    }
}

int main() {

    int tabuleiro [10][10]={0};
    char letras [] = "ABCDEFGHIJ";

    posicionarNavio (tabuleiro, 1, 2, 'H');
    posicionarNavio (tabuleiro, 4, 0, 'V');
    posicionarNavio (tabuleiro, 3, 2, 'D');
    posicionarNavio (tabuleiro, 8, 6, 'c');

    // Exibindo o tabuleiro com os navios em suas posições
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < 10; i++){
        printf("%c  ", letras[i]);
        for (int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
