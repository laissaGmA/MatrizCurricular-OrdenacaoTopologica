#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

//#define DEBUG

struct listas_enc {
    no_t *cabeca;
    no_t *cauda;
    int tamanho;
};

//cria uma lista vazia
lista_enc_t *cria_lista_enc(void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL) {
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void add_cauda(lista_enc_t *lista, no_t *elemento) {
    if (lista == NULL || elemento == NULL) {
        fprintf(stderr, "add_cauda: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0) {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desconectar_no(elemento);
   } else {
        // Remove qualquer ligação antiga
        desconectar_no(elemento);
        // Liga cauda da lista com novo elemento
        conectar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}

void imprimi_lista(lista_enc_t *lista) {
    no_t *no = NULL;

    if (lista == NULL) {
        fprintf(stderr, "imprime_lista: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

    no = lista->cabeca;

    while (no) {
        printf("Dados: %p\n", obter_dado(no));

        no = obter_proximo(no);
    }
}

void imprimi_lista_tras(lista_enc_t *lista) {
    no_t *no = NULL;

    if (lista == NULL) {
        fprintf(stderr, "imprime_lista: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

    no = lista->cauda;

    while (no) {
        printf("Dados: %p\n", obter_dado(no));

        no = obter_anterior(no);
    }
}

int lista_vazia(lista_enc_t *lista) {
    return (lista->tamanho == 0) ? TRUE : FALSE;
}

no_t *obter_cabeca(lista_enc_t *lista) {
    if (lista == NULL) {
        fprintf(stderr, "obter_cabeca: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

    return lista->cabeca;
}

no_t *obter_cauda(lista_enc_t *lista) {
    if (lista == NULL) {
        fprintf(stderr, "obter_cabeca: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

    return lista->cauda;
}

no_t *remover_cauda(lista_enc_t *lista) {
    no_t *anterior;
    no_t *removido;

    if (lista == NULL) {
        fprintf(stderr, "remover_cauda: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

    if (lista->cauda == NULL)
        return NULL;

    removido = lista->cauda;

    if (lista->cauda == lista->cabeca) {
        lista->tamanho = 0;

        lista->cauda = NULL;
        lista->cabeca = NULL;

        return removido;
    }

    anterior = obter_proximo(lista->cauda);
    desconectar_no(removido);
    lista->cauda = anterior;
    desconectar_no_proximo(anterior);
    lista->tamanho--;

    return removido;
}

no_t *remover_cabeca(lista_enc_t *lista) {
    no_t *proximo;
    no_t *removido;

    if (lista == NULL) {
        fprintf(stderr, "remover_cabeca: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

    if (lista->cabeca == NULL)
        return NULL;

    removido = lista->cabeca;

    if (lista->cauda == lista->cabeca) {
        lista->tamanho = 0;

        lista->cauda = NULL;
        lista->cabeca = NULL;

        return removido;
    }

    proximo = obter_proximo(lista->cabeca);
    desconectar_no(removido);
    lista->cabeca = proximo;
    desconectar_no_anterior(proximo);
    lista->tamanho--;

    return removido;
}

void *remover_no(lista_enc_t *lista, no_t *no_removido) {
    no_t *meu_no;
    void *dado;

    no_t *proximo;
    no_t *anterior;

    if (lista == NULL || no_removido == NULL) {
        fprintf(stderr, "remover_no: ponteiros inválidos");
        exit(EXIT_FAILURE);
    }

    // Varre lista até encontrar nó
    meu_no = obter_cabeca(lista);

    while (meu_no) {
        dado = obter_dado(meu_no);

        if (meu_no == no_removido) {
            if (meu_no == lista->cabeca)
                remover_cabeca(lista);
            else if (meu_no == lista->cauda)
                remover_cauda(lista);
            else {
                proximo = obter_proximo(meu_no);
                anterior = obter_anterior(meu_no);
                conectar_nos(anterior, proximo);
                lista->tamanho--;
            }
            free(meu_no);
            break;
        }
        meu_no = obter_proximo(meu_no);
    }

    return dado;
}