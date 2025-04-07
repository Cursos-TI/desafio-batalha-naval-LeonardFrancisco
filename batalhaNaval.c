#define MAR 0
#define TAMANHONAVIO 3
#define NAVIO 3
#define LINHAS 10
#define COLUNAS 10

#include <stdio.h>

//Função pra verificar se os navios não se sobrepõem ou estão fora do tabuleiro.
int verificarPosicao(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, char direcao){
    for (int i = 0; i < TAMANHONAVIO; i++){
        if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS || tabuleiro[linha][coluna] == NAVIO){
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
void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, char direcao){
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


//Habilidade Cone
void habilidadeCone(int tabuleiro[LINHAS][COLUNAS], int linha_topo, int coluna_topo){
    if (linha_topo + 3 > LINHAS || coluna_topo + 2 > COLUNAS || coluna_topo - 2 < 0){ //Verificação de posicionamento
        printf("POSIÇAO DE CONE INVÁLIDA!\n");
    }else{
        for (int i = 0; i < 3 ; i++){
            int inicio = coluna_topo - i;
            int fim = coluna_topo + i;

            for (int j = inicio; j <= fim; j++){
                tabuleiro[linha_topo + i][j] = (tabuleiro[linha_topo + i][j] == NAVIO) ? 5 : 1;
            }
        }
    }  
}


//Habilidade Octaedro
void habilidadeOctaedro(int tabuleiro[LINHAS][COLUNAS], int linha_centro, int coluna_centro){
    if (linha_centro + 1 > LINHAS || linha_centro - 1 < 0 || coluna_centro + 1 > COLUNAS || coluna_centro - 1 < 0){ //Verificação de posicionamento
        printf("POSIÇAO DE OCTAEDRO INVÁLIDA!\n");
    }else{
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i == 0 && j == 0) || (i == 0 && j != 0) || (i != 0 && j == 0)) {
                    int l = linha_centro + i;
                    int c = coluna_centro + j;
                    tabuleiro[l][c] = (tabuleiro[l][c] == NAVIO) ? 5 : 1;
                }
            }
        }
    }
    
}


//Habilidade Cruz
void habilidadeCruz(int tabuleiro[LINHAS][COLUNAS], int linha_centro, int coluna_centro){
    if (linha_centro + 1 >= LINHAS || linha_centro - 1 < 0 && coluna_centro + 2 >= COLUNAS || coluna_centro - 2 < 0){ //Verificação de posicionamento
        printf("POSIÇAO DE CRUZ INVÁLIDA!\n");
        
    }else{
        for (int i = -1; i <= 1; i++){
            for (int j = -2; j <= 2; j++){
                if ((i == 0 && j == 0) || (i == 0 && j != 0) || (i != 0 && j == 0)) {
                    int l = linha_centro + i;
                    int c = coluna_centro + j;
                    tabuleiro[l][c] = (tabuleiro[l][c] == NAVIO) ? 5 : 1;
                }
            }
            
        }
    }
    
}


int main() {

    int tabuleiro [LINHAS][COLUNAS]={0};
    char letras [] = "ABCDEFGHIJ";

    //Chamando função pra posicionar os navios
    posicionarNavio (tabuleiro, 1, 2, 'H');
    posicionarNavio (tabuleiro, 4, 0, 'V');
    posicionarNavio (tabuleiro, 3, 2, 'D');
    posicionarNavio (tabuleiro, 8, 6, 'c');

    //Aplicando as habilidades no tabuleiro
    habilidadeCone(tabuleiro, 3, 2);
    habilidadeOctaedro(tabuleiro, 1, 3);
    habilidadeCruz (tabuleiro, 7, 6);

    // Exibindo o tabuleiro com os navios em suas posições e as posíveis posições atingidas pelas habilidades.
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < LINHAS; i++){
        printf("%c  ", letras[i]);
        for (int j = 0; j < COLUNAS; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
