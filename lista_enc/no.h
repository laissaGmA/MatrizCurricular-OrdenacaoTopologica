#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED


typedef struct nos no_t;

no_t *criar_no(void *dado);

void conectar_nos(no_t *origem, no_t *destino);
void desconectar_no(no_t *no);

void desconectar_no_anterior(no_t *no);
void desconectar_no_proximo(no_t *no);

no_t *obter_proximo(no_t *no);
no_t *obter_anterior(no_t *no);
void *obter_dado(no_t *no);

#endif // NO_H_INCLUDED