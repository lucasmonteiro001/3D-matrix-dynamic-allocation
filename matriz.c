#include "matriz.h"

Matriz3D CriaMatriz3D (int numPlanos, int numLinhas, int numColunas) {

    Matriz3D matriz; // Variável que vai conter a matriz lida do arquivo de entrada

    int i = 0; // Variável que vai representar um contador para os Planos
    int j = 0; // Variável que vai representar um contador para as Linhas
    int k = 0; // Variável que vai representar um contador para as Colunas

    /*
     * Procedimento que faz a alocação de uma matriz 3D, com i numPlanos, j numLinhas e k numColunas
    */
    matriz = (double ***)malloc(numPlanos * sizeof(double **)); // Aloca para os Planos

    for(i = 0; i < numPlanos; i++) {
        matriz[i] = (double **)malloc(numLinhas * sizeof(double*)); // Aloca para as Linhas
    }

    for(i = 0; i < numPlanos; i++) {
        for(j = 0; j < numLinhas; j++) {
            matriz[i][j] = (double *)malloc(numColunas * sizeof(double)); // Aloca para as Colunas
        }
    }

    /*
     * Atribuição de todas as posições da matriz com o valor Zero.
    */
    for(i = 0; i < numPlanos; i++) {
        for(j = 0; j < numLinhas; j++) {
            for(k = 0; k < numColunas; k++) {
                matriz[i][j][k] = 0;
            }
        }
    }

    return matriz;
}

void ImprimeMatriz (FILE *arqSaida, Matriz3D matriz, int numPlanos, int numLinhas, int numColunas) {

    int i = 0; // Variável que vai representar um contador para os Planos
    int j = 0; // Variável que vai representar um contador para as Linhas
    int k = 0; // Variável que vai representar um contador para as Colunas

    /*
     * Impressão de todas as casas [i][j][k] da matriz, com 1 casa de precisão
    */
    for(i = 0; i < numPlanos; i++) {
        for(j = 0; j < numLinhas; j++) {
            for(k = 0; k < numColunas; k++) {
                fprintf(arqSaida, "%.1lf",matriz[i][j][k]);
                if(k != numColunas - 1) fprintf(arqSaida, " ");
            }
            if(i != numPlanos && j != numLinhas) fprintf(arqSaida, "\n");
        }
    }
}

void DesalocaMatriz (Matriz3D matriz, int numPlanos, int numLinhas, int numColunas) {

    int i = 0; // Variável que vai representar um contador para os Planos
    int j = 0; // Variável que vai representar um contador para as Linhas

    /*
     * Processo para liberar as colunas
    */
    for(i = 0; i < numPlanos; i++) {
        for(j = 0; j < numLinhas; j++) {
            free(matriz[i][j]);
        }
    }

    /*
     * Processo para liberar as linhas
    */
    for(i = 0; i < numPlanos; i++) {
        free(matriz[i]);
    }

    free(matriz); // Processo para liberar os planos
}
