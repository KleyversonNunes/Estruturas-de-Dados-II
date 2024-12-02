/*
    Aluno: Kleyverson Nunes da Silva
    Matrícula: 202311140004
    Atividade: Implementação de grafo na forma de lista encadeada
*/

#include <stdio.h>
#include <stdlib.h>

// Definindo as estruturas
#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500

typedef int TipoValorVertice;
typedef int TipoPeso;
typedef struct TipoItem
{
    TipoValorVertice Vertice;
    TipoPeso Peso;
}TipoItem;
typedef struct TipopCelula *TipoApontador;
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

int main()
{
    return 0;
}