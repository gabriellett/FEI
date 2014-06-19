#include <stdio.h>
#include <stdlib.h>

struct tItem
{
    int chave;
    struct tItem *proximo, *anterior;
};

struct tLDDE
{
    struct tItem *primeiro;
    struct tItem *ultimo;
    int quantidade;
};

struct tItem * criaItem()
{
    struct tItem *it;
    it = (struct tItem*) malloc(sizeof(struct tItem));
    if(it!=NULL)
    {
        it->proximo = it->anterior = NULL;
    }
    return it;
}

void insereLDDE(struct tLDDE *lista, int valor)
{
    struct tItem *novo = criaItem(), *anterior=NULL, *atual=lista->primeiro;
    novo->chave=valor;
    int achei=0;

    if(lista->primeiro == NULL && lista->ultimo == NULL)
    {
        lista->primeiro = lista->ultimo = novo;
        lista->quantidade++;
    }
    else
    {
        while(atual!=NULL && !achei)
        {
            if(atual->chave == novo->chave){
                return;
            }
            if(atual->chave > novo->chave)
            {
                achei = 1;
            }
            else
            {
                anterior = atual;
                atual = atual->proximo;
            }
        }
        if(achei)
        {
            if(anterior == NULL)
            {
                novo->proximo = atual;
                atual->anterior = novo;
                lista->primeiro = novo;
                lista->quantidade++;
            }
            else
            {
                novo->anterior = anterior;
                anterior->proximo = novo;
                novo->proximo = atual;
                atual->anterior = novo;
                lista->quantidade++;
            }
        }
        else
        {
            anterior->proximo = novo;
            novo->anterior = anterior;
            lista->ultimo = novo;
            lista->quantidade ++;
        }
    }
}

void ordenaIF(struct tLDDE *lista)
{
    struct tItem *auxiliar = lista->primeiro;

    while(auxiliar!=NULL)
    {
        printf("%d\n", auxiliar->chave);
        auxiliar=auxiliar->proximo;
    }
}
void ordenaFI(struct tLDDE *lista)
{
    struct tItem *auxiliar = lista->ultimo;

    while(auxiliar!=NULL)
    {
        printf("%d\n", auxiliar->chave);
        auxiliar=auxiliar->anterior;
    }
}
void mostraLDDE(struct tLDDE *lista, int quantidade)
{
    if(quantidade%2==0)
    {
        ordenaIF(lista);
    }
    else
    {
       ordenaFI(lista);
    }
}

void removeLDDE(struct tLDDE *lista, struct tItem *removido)
{
    if(removido!=NULL)
    {
        if(lista->primeiro==removido)
        {
            if(removido->proximo==NULL)
            {
                lista->primeiro=NULL;
                lista->ultimo==NULL;
            }
            else
            {
                lista->primeiro=removido->proximo;
                lista->primeiro->anterior=NULL;
            }
        }
        else if(lista->ultimo==removido)
        {
            lista->ultimo=removido->anterior;
            removido->anterior->proximo=NULL;
        }
        else
        {
             removido->anterior->proximo=removido->proximo;
             removido->proximo->anterior=removido->anterior;
        }
        lista->quantidade--;
    }
}

void encontraDireita (struct tLDDE *lista, int n)
{
    int i;
    struct tItem *auxiliar = lista->primeiro;

    if(lista->quantidade>0)
    {
        for(i=0; i<n; i++)
        {
            if (auxiliar == lista->ultimo)
                auxiliar = lista->primeiro;
            else
                auxiliar=auxiliar->proximo;
        }
        removeLDDE(lista, auxiliar);
    }
}

void encontraEsquerda (struct tLDDE *lista, int n)
{
    int i;
    struct tItem *auxiliar = lista->primeiro;
    if(lista->quantidade>0)
    {
        for(i=0; i<n; i++)
        {
            if (auxiliar == lista->primeiro)
                auxiliar = lista->ultimo;
            else
                auxiliar = auxiliar->anterior;
        }
        removeLDDE(lista, auxiliar);
    }
}

int main(void)
{
    int aux, q, i, n;
    char caractere;

    struct tLDDE * criaLDDE(void)
    {
        struct tLDDE *lista;
        lista = (struct tLDDE*) malloc(sizeof(struct tLDDE));
        if(lista!=NULL)
        {
            lista->primeiro = lista->ultimo = NULL;
            lista->quantidade = 0;
        }
        return lista;
    }
    struct tLDDE lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;
    lista.quantidade = 0;

    scanf("%d", &q);
    for(i=0; i<q; i++)
    {
        scanf("%d\n", &n);
        insereLDDE(&lista, n);
        printf("MOSTA:\n");
        //mostraLDDE(&lista, lista.quantidade);
    }
    while(scanf("%c:%d\n", &caractere, &aux)!=EOF)
    {
        if(toupper(caractere=='E'))
            encontraEsquerda(&lista, aux);
        else
            encontraDireita(&lista, aux);
    }
    if(lista.quantidade>0)
        mostraLDDE(&lista, lista.quantidade);
}
