#include <stdio.h>
#include <stdlib.h>
#include "./grafo/grafo.h"

int main(void) {
    grafo_t *g;

    // Ler o grafo a partir do arquivo
    g = ler_arquivo();

    printf("\n");
    printf("            MATRIZ CURRICULAR DO CURSO DE BACHARELADO EM CIENCIA DA COMPUTACAO - UFAPE       \n");
    printf("\n");
    // Imprime os vértices do grafo
    imprime_vertices(g);
    printf("\n");

    printf("              MATRIZ DE DEPENDENCIAS DIRETAS DAS DISCIPLINAS DO CURSO DE BACHARELADO EM CIENCIA DA COMPUTACAO - UFAPE        \n");
    printf("\n");
    // Imprime a matriz de dependências diretas das disciplinas
    imprime_matriz(g);

    // Realiza a ordenação topológica
    ordenacao_topologica(g);

    // Exporta o grafo em formato DOT
    exportar_grafo_dot("grafo.dot", g);

    // Libera a memória alocada para o grafo
    libera_grafo(g);

    return EXIT_SUCCESS;
}