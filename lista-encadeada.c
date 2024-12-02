/*
    Aluno: Kleyverson Nunes da Silva
    Matrícula: 202311140004
    Atividade: Implementação de grafo na forma de lista encadeada
*/

#include <stdio.h>
#include <stdlib.h>

// Definindo as estruturas do grafo
#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500
#define TRUE 1
#define FALSE 0

typedef int TipoValorVertice;
typedef int TipoPeso;
typedef struct TipoItem
{
    TipoValorVertice Vertice;
    TipoPeso Peso;
}TipoItem;
typedef struct TipoCelula *TipoApontador;
struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;
typedef struct TipoLista
{
    TipoApontador Primeiro, Ultimo;
}TipoLista;
typedef struct TipoGrafo
{
    TipoLista Adj[MAXNUMVERTICES + 1];
    TipoValorVertice NumVertices;
    short NumArestas;
}TipoGrafo;

// Implementando os métodos sobre lista
void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

// Implementando os métodos sobre grafo
void FGVazio(TipoGrafo *Grafo)
{
    long i;
    for(i = 0; i < Grafo->NumVertices; i++) FLVazia(&Grafo->Adj[i]);
}

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)
{
    TipoItem x;
    x.Vertice = *V2;
    x.Peso = *Peso;
    Insere(x,&Grafo->Adj[*V1]);
}

short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo)
{
    TipoApontador Aux;
    short EncontrouAresta = FALSE;
    Aux = Grafo->Adj[Vertice1].Primeiro->Prox;
    while(Aux != NULL && EncontrouAresta == FALSE)
    {
        if(Vertice2 == Aux->Item.Vertice) EncontrouAresta = TRUE;
        Aux = Aux->Prox;
    }
}

// Métodos para obter listas de adjacentes
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{
    return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{
    return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj)
{
    *Adj = (*Prox)->Item.Vertice;
    *Peso = (*Prox)->Item.Peso;
    *Prox = (*Prox)->Prox;
    if(*Prox == NULL) *FimListaAdj = TRUE;
}

// Método para retirar da lista
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{
    TipoApontador q;
    if(Vazia(*Lista) || p == NULL || p->Prox == NULL)
    {
        printf("Erro: Lista vazia ou posicao nao existe\n");
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if(p->Prox == NULL) Lista->Ultimo = p;
    free(q);
}

// Mais métodos sobre grafos
void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)
{
    TipoApontador AuxAnterior, Aux;
    short EncontrouAresta = FALSE;
    TipoItem x;
    AuxAnterior = Grafo->Adj[*V1].Primeiro;
    while(Aux != NULL && EncontrouAresta == FALSE)
    {
        if(*V2 == Aux->Item.Vertice)
        {
            Retira(AuxAnterior,&Grafo->Adj[*V1],&x);
            Grafo->NumArestas--;
            EncontrouAresta == TRUE;
        }
        AuxAnterior = Aux;
        Aux = Aux->Prox;
    }
}

void LiberaGrafo(TipoGrafo *Grafo)
{
    TipoApontador AuxAnterior, Aux;
    for(int i = 0;i < Grafo->NumVertices; i++)
    {
        Aux = Grafo->Adj[i].Primeiro->Prox;
        free(Grafo->Adj[i].Primeiro);
        Grafo->Adj[i].Primeiro = NULL;
        while(Aux != NULL)
        {
            AuxAnterior = Aux;
            Aux = Aux->Prox;
            free(AuxAnterior);
        }
    }
    Grafo->NumVertices = 0;
}

void ImprimeGrafo(TipoGrafo *Grafo)
{
    int i;
    TipoApontador Aux;
    for(i = 0; i < Grafo->NumVertices; i++)
    {
        printf("Vertice%2d: ",i);
        if(!Vazia(Grafo->Adj[i]))
        {
            Aux = Grafo->Adj[i].Primeiro->Prox;
            while(Aux != NULL)
            {
                printf("%3d (%d)",Aux->Item.Vertice, Aux->Item.Peso);
                Aux = Aux->Prox;
            }
        }
        putchar('\n');
    }
}

int main()
{
    printf("Isso aqui e o capeta!\n");
    return 0;
}
