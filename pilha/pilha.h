#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef struct pilhas pilha_t;

pilha_t *criar_pilha(void);

void push(void *dado, pilha_t *pilha);
void *pop(pilha_t *pilha);

int pilha_vazia(pilha_t *pilha);
void liberar_pilha(pilha_t *pilha);

#endif // PILHA_H_INCLUDED