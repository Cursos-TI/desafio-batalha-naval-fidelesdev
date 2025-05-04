#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

bool verificarPosicoes(int arrayPosicoes[], int tamanho){
    bool conflito = false; 
    for(int i = 0; i < tamanho; i++){
        if(arrayPosicoes[i] != 0){
            conflito = true;
            break;
        }
    }
    return conflito;
}

int main() {
    int tabuleiro[10][10];
    int nLinhas = sizeof(tabuleiro)/sizeof(*tabuleiro);
    int nColunas = sizeof(*tabuleiro)/sizeof(**tabuleiro);
    for(int i = 0; i < nLinhas; i++){
        for(int j = 0; j < nColunas; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //inserção do navio vertical no tabuleiro
    int navioVertical[] = {3,3,3};
    int posLinhaNavioVertical = 3;
    int posColunaNavioVertical = 8;
    int tamanhoNavioVertical = sizeof(navioVertical)/sizeof(*navioVertical);

    if(
        posColunaNavioVertical < 0 || posColunaNavioVertical > nColunas ||
        posLinhaNavioVertical < 0 || posLinhaNavioVertical > nLinhas
    ){
        printf("coordenada do navio vertical invalida");
        return 1;
    }
    else if(posLinhaNavioVertical-1 + tamanhoNavioVertical > nLinhas){
        printf("navio muito grande para o tabuleiro na posicao (%d,%d)", posLinhaNavioVertical, posColunaNavioVertical);
        return 1;
    }
    for(int i = 0; i < tamanhoNavioVertical; i++){
        tabuleiro[i + posLinhaNavioVertical-1][posColunaNavioVertical-1] = navioVertical[i];
    }


    int navioHorizontal[] = {3,3,3};
    int posLinhaNavioHorizontal = 3;
    int posColunaNavioHorizontal = 4;
    int tamanhoNavioHorizontal = sizeof(navioHorizontal)/sizeof(*navioHorizontal);
    if(
        posColunaNavioHorizontal < 0 || posColunaNavioHorizontal > nColunas ||
        posLinhaNavioHorizontal < 0 || posLinhaNavioHorizontal > nLinhas
    ){
        printf("coordenada do navio horizontal invalida");
        return 1;
    }
    else if(posLinhaNavioHorizontal-1 + tamanhoNavioHorizontal > nLinhas){
        printf("navio muito grande para o tabuleiro na posicao (%d,%d)", posLinhaNavioHorizontal, posColunaNavioHorizontal);
        return 1;
    }
    int posicoes[tamanhoNavioHorizontal];
    for(int i = 0; i < tamanhoNavioHorizontal; i++){
        posicoes[i] = tabuleiro[posLinhaNavioHorizontal-1][posColunaNavioHorizontal-1 + i];
    }
    if(verificarPosicoes(posicoes, tamanhoNavioHorizontal) == true){
        printf("nao foi possivel posicionar o navio horizontal, conflito com outro navio\n");
        return 1;
    }
    for(int i = 0; i < tamanhoNavioHorizontal; i++){
        tabuleiro[posLinhaNavioHorizontal-1][i + posColunaNavioHorizontal-1] = navioHorizontal[i];
    }

    //mostrar resultado do tabuleiro
    for(int i = 0; i < nLinhas; i++){
        for(int j = 0; j < nColunas; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
