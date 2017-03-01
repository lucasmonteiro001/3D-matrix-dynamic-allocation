#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Definição do tipo inteiro NumeroInstancias, que receberá o nº de instancias que o programa será executado
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef int NumeroInstancias;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Definição do tipo da Matriz principal
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef double*** Matriz3D;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Definição da estrutura que armazenará as informações sobre a matriz
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct DadosMatriz {
    int X; // Número de planos
    int Y; // Número de linhas
    int Z; // Número de colunas
} DadosMatriz;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Protótipo: Matriz3D CriaMatriz3D (int numPlanos, int numLinhas, int numColunas);
 * Função:    Cria uma matriz com três dimensões
 * Entrada:   - int numPlanos:  número de planos
 *            - int numLinhas:  número de linhas
 *            - int numColunas: número de colunas
 * Saída:     Retorna um apontador para uma matriz com três dimensões
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
Matriz3D CriaMatriz3D (int numPlanos, int numLinhas, int numColunas);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Protótipo: void ImprimeMatriz (FILE *arqSaida, Matriz3D matriz, int numPlanos, int numLinhas, int numColunas);
 * Função:    Imprime uma matriz com três dimensões
 * Entrada:   - FILE *arqSaida: destino da impressão
 *            - Matriz3D matriz: matriz com 3 dimensões
 *            - int numPlanos:  número de planos da matriz
 *            - int numLinhas:  número de linhas da matriz
 *            - int numColunas: número de colunas da matriz
 * Saída:     Nenhuma
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ImprimeMatriz (FILE *arqSaida, Matriz3D matriz, int numPlanos, int numLinhas, int numColunas);

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Protótipo: void DesalocaMatriz (Matriz3D matriz, int numPlanos, int numLinhas, int numColunas);
 * Função:    Desaloca uma matriz de três dimensões
 * Entrada:   - Matriz3D matriz: matriz com 3 dimensões
 *            - int numPlanos:  número de planos da matriz
 *            - int numLinhas:  número de linhas da matriz
 *            - int numColunas: número de colunas da matriz
 * Saída:     Nenhuma
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void DesalocaMatriz (Matriz3D matriz, int numPlanos, int numLinhas, int numColunas);


#endif // MATRIZ_H_INCLUDED
