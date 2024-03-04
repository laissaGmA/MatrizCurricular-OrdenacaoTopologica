#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../fila/fila.h"
#include "../pilha/pilha.h"

#include "grafo.h"

struct vertices
{
    int id;
    int n_dependencias;
    int visitado;
    char *titulo;
};

struct arestas
{
    int dependencia;
    int exported;

};

struct grafos
{
    int n_vertices;
    vertice_t *vertices;
    aresta_t **matriz_adj;
};


grafo_t *cria_grafo(int vertices)
{
    int i;
    aresta_t **matriz_adj;
    grafo_t *g = malloc(sizeof(grafo_t));

    if (g == NULL)
    {
        perror("cria_grafo (g)");
        exit(EXIT_FAILURE);
    }

    g->n_vertices = vertices;
    g->vertices = malloc(vertices * sizeof(vertice_t));

    if (g->vertices == NULL)
    {
        perror("cria_grafo (vertices)");
        exit(EXIT_FAILURE);
    }

    memset(g->vertices, 0, vertices * sizeof(vertice_t));

    matriz_adj = malloc(vertices * sizeof(aresta_t *));

    if (matriz_adj == NULL)
    {
        perror("cria_grafo (matriz_adj)");
        exit(EXIT_FAILURE);
    }

    for ( i = 0; i < vertices; i++ )
    {
        matriz_adj[i] = calloc(vertices, sizeof(vertice_t));

        if (matriz_adj[i] == NULL)
        {
            perror("cria_grafo (matriz_adj[i])");
            exit(EXIT_FAILURE);
        }
    }

    g->matriz_adj = matriz_adj;

    return g;
}

grafo_t* Ler_arq(void)
{
    int i=0,id,dep,n,t;
    grafo_t*g;
    aresta_t aresta;
    aresta.dependencia=1;
    char buffer[128];
    FILE *fp;
    fp = fopen ("montagemdagradebcc.txt", "r");
    if (fp == NULL)
    {
        printf ("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    while ((fgets(buffer,128,fp))!=NULL)   
        i++;
    rewind(fp);
   
    g=cria_grafo(i-1);
    fgets(buffer,128,fp);
    while(!feof(fp))
    {
        n=0;
        fscanf(fp,"%d, %[^,]",&id,buffer);
        t=strlen(buffer);
        cria_titulo(g,id,t);
        strcpy(g->vertices[id].titulo,buffer);
       
            while(fscanf(fp,",%d",&dep)==1)
            {
                
                g->matriz_adj[id][dep]=aresta;      
                n++;
                g->vertices[id].n_dependencias=n;
            }
            fscanf(fp,"%*[^\n]");
           

        g->vertices[id].id=id;
    }
    fclose(fp);
    return g;
}

void ordenacao_topologica(grafo_t* g)
{
    int i,j,k=0;

    FILE *file;
    if (g == NULL){
        fprintf(stderr, "ordenacao_topologica: ponteiros invalidos\n");
        exit(EXIT_FAILURE);
    }

    file = fopen("Lista de tarefas.dot", "w");

        if (file == NULL){
        perror("exportar_grafp_dot:");
        exit(EXIT_FAILURE);
    }

    fprintf(file,"Lista de disciplinas a serem cursadas no curso de Ciência da Computação:\n");

    for(j=0; j<g->n_vertices; j++)
    {
        i = dfs(g,j);
        if(i!=0)
        {
            printf("Erro: grafo direcionado.\n");
            exit(EXIT_FAILURE);
        }
    }

    fila_t* Q = cria_fila();
    for(i=0;i<g->n_vertices;i++){
        if(g->vertices[i].n_dependencias==0){
            enqueue((void*)i, Q);
            printf("N[%d]=0.\n", i);
        }
    }

    while(!fila_vazia(Q))
    {
        i = (int)dequeue(Q);
        fprintf(file,"%d� %s, ID:%d\n",k,g->vertices[i].titulo,g->vertices[i].id);
        if(g->vertices[i].n_dependencias==0)
        {
            for(j=0; j<g->n_vertices; j++)
            {
                if(adjacente(g, j, i)==1)
                {
                    g->vertices[j].n_dependencias--;
                    if(g->vertices[j].n_dependencias == 0){
                        enqueue((void*)j, Q);
                    }
                }
            }
        }
    k++;
    }
    libera_fila(Q);

}

int testa_direcional(grafo_t* g)
{
   int i, j;
   for(i=0; i<g->n_vertices; i++){
        for(j=0; j<g->n_vertices; j++){
            if((adjacente(g, j, i)==1) && (adjacente(g, i, j)==1)){
                return 1;
            }
        }
    }
    return 0;
}

void libera_grafo (grafo_t *g)
{
    int i;

    if (g == NULL)
    {
        perror("libera_grafo");
        exit(EXIT_FAILURE);
    }

    for (i=0; i < g->n_vertices; i++)
    {
         free(g->matriz_adj[i]);
         free(g->vertices[i].titulo);
    }


    free(g->matriz_adj);
    free(g->vertices);
    free(g);
}


int adjacente(grafo_t *g, int u, int v)
{

    if (u > MAX_VERTICES || v > MAX_VERTICES)
        return FALSE;
              
    return ((g->matriz_adj[u][v].dependencia));
}

int dfs(grafo_t* grafo,int inicial)
{
    int i,init=inicial,ciclo=0;
    pilha_t*pilha=cria_pilha();

    for (i=0; i<grafo->n_vertices; i++)
    {
        grafo->vertices[i].visitado = 0;
    }
    push((void*)inicial,pilha);
  
    while(!pilha_vazia(pilha))
    {
        inicial=(int)pop(pilha);
       


            grafo->vertices[inicial].visitado = 1;

            for (i=0; i<grafo->n_vertices; i++)
            {
                if (adjacente(grafo,i, inicial))
                {
                    if (grafo->vertices[i].visitado == 0)
                    push((void*)i,pilha);

                    if (i==init){
                        printf("grafo direcionado %d\n",i);
                        ciclo = 1;
                    }

                }
        }
    }
    
    libera_pilha(pilha);
    return ciclo;
}

void vertice_set_id(grafo_t *g)
{
    int i;
    for (i=0; i < g->n_vertices; i++)
        g->vertices[i].id = i+1;
}

void imprime_matriz(grafo_t* grafo)
{
    int i,j;
          	printf("     ");
	for(i=0; i < grafo->n_vertices; i++)
        printf("%2d ",i);
        printf("\n");
    for(i=0; i < grafo->n_vertices; i++)
        printf("---");
        printf("\n");
	for (i=0; i < grafo->n_vertices; i++){
            printf("%2d | ",i);
		for (j=0; j < grafo->n_vertices; j++)
			printf("%2d ", grafo->matriz_adj[i][j].dependencia);
			printf("\n");
	}
}

void imprime_vertices(grafo_t *g)
{
    int i;
    for(i=0; i<g->n_vertices;i++)
        printf("%d\t%30s numero de dependencias diretas: %d\n",i,g->vertices[i].titulo,g->vertices[i].n_dependencias);
}

void cria_titulo(grafo_t* g,int id,int t){
    g->vertices[id].titulo=(char *)malloc(sizeof(char) * (t+1));

}

void exportar_grafo_dot(const char *filename, grafo_t *grafo) {
    #ifdef DEBUG
        printf("\nexporta grafo:");
    #endif
    FILE *file;
    if (filename == NULL || grafo == NULL){
        fprintf(stderr, "exportar_grafp_dot: ponteiros invalidos\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(filename, "w");

    if (file == NULL){
        perror("exportar_grafp_dot:");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < grafo->n_vertices; i++)
        for (int j = 0; j <grafo->n_vertices; j++)
            grafo->matriz_adj[i][j].exported=0;


    fprintf(file, "digraph {\n");
    for (int i = 0; i < grafo->n_vertices; i++) {
        for (int j = 0; j <grafo->n_vertices; j++) {
            if ((!grafo->matriz_adj[i][j].exported &&!grafo->matriz_adj[j][i].exported )&& grafo->matriz_adj[i][j].dependencia) {

                fprintf(file, "\t\"%s\"-> \"%s\" ;\n",grafo->vertices[i].titulo,grafo->vertices[j].titulo);
                grafo->matriz_adj[i][j].exported = TRUE;
            }
        }
    }
    fprintf(file, "}\n");
    fclose(file);

}