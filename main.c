#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"     // Biblioteca para manipulação de dados de entrada e saída
#include "matriz.h" // Biblioteca que contém as operações em matriz

int main(int argc, char *argv[])
{

    FILE *arqEntrada = AbreArquivo(argv[1], "r"); // Arquivo que conterá as informações e instruções do programa
    FILE *arqSaida   = AbreArquivo(argv[2], "w"); // Arquivo que conterá a saída (resultado) do programa após sua execução

    NumeroInstancias N; fscanf(arqEntrada, "%d", &N); // Armazena o número de instancias a serem executadas em N

    DadosMatriz D;    // Armazena os dados da matriz (x, y, z)

    char operador;    // Operador, que poderá ser '+', '-' ou '='

    double aux = 0;   // Variável que vai conter o double lido do arquivo, para, então, ser armazenado na matriz

    Matriz3D matriz; // Matriz principal do programa

    if(N != 0) { // Se o arquivo contém ao menos uma matriz
        /*
         * Bloco de código que executa N vezes, onde N é o número de instâncias
        */
        while(N-- != 0) {

            /* Lê as dimensões da matriz
             * e as atribui para a estrutura DadosMatriz
            */
            fscanf(arqEntrada, "%d", &D.X);
            fscanf(arqEntrada, "%d", &D.Y);
            fscanf(arqEntrada, "%d", &D.Z);

            fseek(arqEntrada, SEEK_CUR, 1);       // Move o cursor para a próxima linha

            matriz = CriaMatriz3D(D.X, D.Y, D.Z); // Aloca dinamicamente a matriz 3D

            int xyz = D.X * D.Y * D.Z;            // xyz é a quantidade de vezes que será feita a leitura de uma determinada matriz

            int x = 0, y = 0, z = 0;              // Variáveis auxiliares para ajudar no caminhamento na matriz

            while (xyz-- != 0) {

                fscanf(arqEntrada, "%lf", &aux); // Lê do arquivo de entrada o valor que é para colocar na matriz

                matriz[x][y][z++] = aux; // A incrementação do z passa para a próxima coluna da linha

                /*
                 * Bloco de código que faz o caminhamento na matriz, primeiro percorre todas as colunas de uma linha,
                 * depois passa para a próxima linha e percorre todas as suas colunas. Faz isso até chegar ao número máximo
                 * de linhas. Quando chega ao número máximo de linhas passa para o próximo plano de começa o processo novamente.
                */
                if (z == D.Z) {// Se chegou ao final das colunas de uma linha
                    z = 0;
                    y++; // Passa para a próxima linha
                }
                if (y == D.Y) { // Se chegou no final das linhas de um plano
                    x++;
                    y = 0;
                    z = 0;
                }
            }

            fseek(arqEntrada, SEEK_CUR, 1);      // Move o cursor para a próxima linha

            fscanf(arqEntrada, "%c", &operador); // Após ler todos os elementos da matriz, verifica qual é a operação a ser feita

            fseek(arqEntrada, SEEK_CUR, 1);      // Move o cursor para a próxima linha

            /*
             * Bloco de operações para uma instância
            */
            do {

                xyz = D.X * D.Y * D.Z;  // xyz é a quantidade de vezes que será feita a leitura de uma determinada matriz

                x = 0, y = 0, z = 0; // Variáveis auxiliares para ajudar no caminhamento na matriz

                /* Dado que uma matriz de tamanho X * Y * Z conterá X * Y linhas no arquivo
                 * leremos esse valor para executar cada instância
                */
                while (xyz-- != 0) {

                    fscanf(arqEntrada, "%lf", &aux); // Lê do arquivo de entrada o valor que é para colocar na matriz

                    if(operador == '+')
                        matriz[x][y][z++] += aux; // A incrementação do z passa para a próxima coluna da linha
                    else if(operador == '-')
                        matriz[x][y][z++] -= aux; // A incrementação do z passa para a próxima coluna da linha

                    /*
                     * Bloco de código que faz o caminhamento na matriz, primeiro percorre todas as colunas de uma linha,
                     * depois passa para a próxima linha e percorre todas as suas colunas. Faz isso até chegar ao número máximo
                     * de linhas. Quando chega ao número máximo de linhas passa para o próximo plano de começa o processo novamente.
                    */
                    if (z == D.Z) {// Se chegou ao final das colunas de uma linha
                        z = 0;
                        y++; // Passa para a próxima linha
                    }
                    if (y == D.Y) { // Se chegou no final das linhas de um plano
                        x++;
                        y = 0;
                        z = 0;
                    }
                }

                fseek(arqEntrada, SEEK_CUR, 1); // Move o cursor para a próxima linha

                fscanf(arqEntrada, "%c", &operador); // Após ler todos os elementos da matriz, verifica qual é a operação a ser feita

                fseek(arqEntrada, SEEK_CUR, 1); // Move o cursor para a próxima linha

            } while (operador != '=' && operador != '\n' && operador != EOF); // Se o operador for '=', quer dizer que é o fim de uma instância

            ImprimeMatriz(arqSaida, matriz, D.X, D.Y, D.Z);

            if(N > 0) fprintf(arqSaida, "\n");

            DesalocaMatriz(matriz, D.X, D.Y, D.Z);

        }
    }
    // Se o N da entrada for igual a zero
    else {
        fprintf(arqSaida, "");
    }

    FechaArquivo(arqEntrada);
    FechaArquivo(arqSaida);

    return 0;
}
