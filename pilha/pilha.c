#include <stdlib.h>
#include <stdio.h>

#include "../lista_enc/lista_enc.h"
#include "../lista_enc/no.h"
#include "pilha.h"

//#define DEBUG

struct pilhas {
	lista_enc_t *dados;
};


// Cria uma pilha genérica
pilha_t *criar_pilha(void) {
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));

    if (pilha == NULL) {
        perror("criar_pilha:");
        exit(EXIT_FAILURE);
    }

    pilha->dados = cria_lista_enc();

    return pilha;
}

// Adiciona elemento
void push(void *dado, pilha_t *pilha) {
    no_t *no;

    if (pilha == NULL) {
        fprintf(stderr, "push: pilha inválida\n");
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
    printf("push: %p\n", dado);
    #endif // DEBUG

    no = criar_no(dado);
    add_cauda(pilha->dados, no);
}

// Retira elemento do topo
void *pop(pilha_t *pilha) {
    no_t *no;
    void *dado;

    if (pilha == NULL) {
        fprintf(stderr, "pop: pilha inválida!\n");
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
    //printf("pop: %d\n", pilha->data[topo - 1]);
    #endif // DEBUG

    no = remover_cauda(pilha->dados);
    dado = obter_dado(no);
    free(no);

    return dado;
}

void liberar_pilha(pilha_t *pilha) {
    if (pilha == NULL) {
        fprintf(stderr, "Erro em liberar_pilha\n");
        exit(EXIT_FAILURE);
    }

    if (!lista_vazia(pilha->dados)) {
    	fprintf(stderr, "Impossível liberar pilha, ainda há dados\n");
    	exit(EXIT_FAILURE);
    }

    free(pilha->dados);
    free(pilha);
}

int pilha_vazia(pilha_t *pilha) {
    if (pilha == NULL) {
        fprintf(stderr, "pilha_vazia: pilha inválida\n");
        exit(EXIT_FAILURE);
    }

    return lista_vazia(pilha->dados);
}