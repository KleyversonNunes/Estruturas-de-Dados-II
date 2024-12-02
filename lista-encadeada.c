#include <stdlib.h>
#include <stdio.h>

// Definindo as estruturas
//typedef int TipoChave;

typedef struct
{
    int Valor;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct
{
    TipoApontador Primeiro, Ultimo;
}TipoLista;

// Definindo as operações da lista
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

void Imprime(TipoLista Lista)
{
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    while(Aux != NULL)
    {
        printf("%d ",Aux->Item.Valor);
        Aux = Aux->Prox;
    }
}

// Utilizando as estruturas e as operações
int main()
{
    TipoLista Lista1;
    FLVazia(&Lista1);
    
    // Verificando se a lista está vazia
    printf("%d\n",Vazia(Lista1));

    // Criando itens
    TipoItem i1, i2, i3, i4, i5;
    i1.Valor = 100;
    i2.Valor = 200;
    i3.Valor = 300;
    i4.Valor = 400;
    i5.Valor = 500;

    // Criando células
    /*
    TipoCelula c1, c2, c3, c4, c5;
    c1.Item = i1;
    c2.Item = i2;
    c3.Item = i3;
    c4.Item = i4;
    c5.Item = i5;
    */

    // Inserindo itens
    Insere(i1,&Lista1);
    Insere(i2,&Lista1);
    Insere(i3,&Lista1);

    // Exebindo a lista
    Imprime(Lista1);
    //printf("\n");

    // Retirando itens
    TipoApontador PontItem2 = Lista1.Primeiro->Prox->Prox;
    //Retira(PontItem1,&Lista1,&i2); // Retirando i2
    Retira(PontItem2,&Lista1,&i3); // Retirando i3

    // Exibindo a lista
    printf("\n");
    Imprime(Lista1);

    // Adicionando itens
    Insere(i4,&Lista1);
    Insere(i5,&Lista1);

    // Exibindo a lista
    printf("\n");
    Imprime(Lista1);

    return 0;
}