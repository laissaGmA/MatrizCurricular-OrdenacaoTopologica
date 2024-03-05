#include <stdio.h>
#include <stdlib.h>
#include "./grafo/grafo.h"

void menu() {
    printf("========== MENU ==========\n");
    printf("1. Imprimir Grade Curricular\n");
    printf("2. Imprimir Matriz de Dependencias Diretas\n");
    printf("3. Realizar Ordenacao Topologica das Disciplinas\n");
    printf("4. Exportar Grafo em formato DOT\n");
    printf("5. Sair\n");
    printf("==========================\n");
    printf("Escolha uma opcao: ");
}

int main(void) {
    grafo_t *g;
    int opcao;

    // Ler o grafo a partir do arquivo
    g = ler_arquivo();

    do {
        menu();
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("\n");
                printf("            GRADE CURRICULAR DO CURSO DE BACHARELADO EM CIENCIA DA COMPUTACAO - UFAPE       \n");
                printf("\n");
                imprime_vertices(g);
                printf("\n");
                break;
            case 2:
                printf("\n");
                printf("              MATRIZ DE DEPENDENCIAS DIRETAS DAS DISCIPLINAS DO CURSO DE BACHARELADO EM CIENCIA DA COMPUTACAO - UFAPE        \n");
                printf("\n");
                imprime_matriz(g);
                printf("\n");
                break;
            case 3:
                printf("\n");
                printf("            ORDENACAO TOPOLOGICA DAS DISCIPLINAS DO CURSO DE BACHARELADO EM CIENCIA DA COMPUTACAO - UFAPE    \n");
                printf("\n");
                ordenacao_topologica(g);
                printf("\n");
                break;
            case 4:
                printf("Exportando Grafo em formato DOT...\n");
                exportar_grafo_dot("grafo.dot", g);
                printf("Grafo exportado com sucesso!\n\n");
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
    } while (opcao != 5);

    // Libera a memória alocada para o grafo
    libera_grafo(g);

    return EXIT_SUCCESS;
}