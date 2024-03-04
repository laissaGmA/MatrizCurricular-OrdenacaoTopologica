#include <stdio.h>
#include <stdlib.h>
#include "./grafo/grafo.h"


int main(void) {

	grafo_t *g;

	g = Ler_arq();
    
    printf("\n");
    printf("            MATRIZ CURRICULAR DO CURSO DE BACHARELADO EM CIENCIA DA COMPUTACAO - UFAPE       \n");
    printf("\n");
    imprime_vertices(g);
    printf("\n");
    
    printf("              MATRIZ DE DEPENDENCIAS DIRETAS DAS DISCIPLINAS DO CURSO DE BACHARELADO EM CIENCIA DA COMPUTACAO - UFAPE        \n");
    printf("\n");
    imprime_matriz(g);
    ordenacao_topologica(g);
    exportar_grafo_dot("grafo.dot",g);
	libera_grafo(g);

	return EXIT_SUCCESS;
}
