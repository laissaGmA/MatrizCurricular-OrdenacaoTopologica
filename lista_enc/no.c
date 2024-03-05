#include <stdio.h>
#include <stdlib.h>

#include "no.h"

struct nos {
    void *dados;
    no_t *proximo;
    no_t *anterior;
};

// Cria um novo nó
no_t *criar_no(void *dado) {
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL) {
        perror("criar_no:");
        exit(EXIT_FAILURE);
    }

    p->dados = dado;
    p->proximo = NULL;
    p->anterior = NULL;

    return p;
}

void conectar_nos(no_t *origem, no_t *destino) {
    if (origem == NULL || destino == NULL) {
        fprintf(stderr, "conectar_nos: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

    origem->proximo = destino;
    destino->anterior = origem;
}

void desconectar_no(no_t *no) {
    if (no == NULL) {
        fprintf(stderr, "desconectar_no: ponteiro inválido");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
    no->anterior = NULL;
}

void desconectar_no_anterior(no_t *no) {
    if (no == NULL) {
        fprintf(stderr, "desconectar_no_anterior: ponteiro inválido");
        exit(EXIT_FAILURE);
    }

    no->anterior = NULL;
}

void desconectar_no_proximo(no_t *no) {
    if (no == NULL) {
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
}

void *obter_dado(no_t *no) {
    if (no == NULL) {
        fprintf(stderr, "obter_dado: ponteiro inválido");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}

no_t *obter_proximo(no_t *no) {
    if (no == NULL) {
        fprintf(stderr, "obter_proximo: ponteiro inválido");
        exit(EXIT_FAILURE);
    }

    return no->proximo;
}

no_t *obter_anterior(no_t *no) {
    if (no == NULL) {
        fprintf(stderr, "obter_anterior: ponteiro inválido");
        exit(EXIT_FAILURE);
    }

    return no->anterior;
}