#include <stdlib.h>
#include <stdio.h>

#include "../lista_enc/lista_enc.h"
#include "../lista_enc/no.h"
#include "fila.h"

#define FALSE 0
#define TRUE 1

struct filas {
    lista_enc_t *dados;
};

// Cria uma fila genérica
fila_t * cria_fila (void)
{
    fila_t *p = (fila_t*)malloc(sizeof(fila_t));

    if (p == NULL) {
        fprintf(stderr, "Erro ao alocar dados em cria_fila!\n");
        exit(EXIT_FAILURE);
    }

    p->dados = cria_lista_enc();

    return p;
}

// Adiciona elemento na fila
void enqueue(void* dado, fila_t *fila)
{
    no_t *no;

    if (fila == NULL) {
        fprintf(stderr, "enqueue: fila inválida\n");
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
    printf("enqueue: %p\n", dado);
    #endif // DEBUG

    no = criar_no(dado);
    add_cauda(fila->dados, no);
}

// Retira elemento da fila
void *dequeue(fila_t *fila)
{
    no_t *no;
    void *dado;

    if (fila == NULL){
        fprintf(stderr, "dequeue: fila inválida!\n");
        exit(EXIT_FAILURE);
    }

    no = remover_cabeca(fila->dados);
    dado = obter_dado(no);
    free(no);

    return dado;
}

// Libera a memória da fila
void libera_fila(fila_t* fila)
{
    if (fila == NULL) {
        fprintf(stderr, "Erro em libera_fila\n");
        exit(EXIT_FAILURE);
    }

    if (!lista_vazia(fila->dados)){
        fprintf(stderr, "Impossível liberar a fila, ainda há dados\n");
        exit(EXIT_FAILURE);
    }

    free(fila->dados);
    free(fila);
}

// Verifica se a fila está vazia
int fila_vazia(fila_t *fila)
{
    if (fila == NULL) {
        fprintf(stderr, "fila_vazia: fila inválida\n");
        exit(EXIT_FAILURE);
    }

    return lista_vazia(fila->dados);
}