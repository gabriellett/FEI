#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct tDados
{
    int chave;
};

struct tItem
{
    struct tDados info;
    struct tItem *anterior;
    struct tItem *proximo;
};

struct tLdde
{
    struct tItem *primeiro;
    struct tItem *ultimo;
};

struct tLdde * criaLista();
struct tItem * criaItem();
void lerItem(struct tItem *);
void inserir(struct tLdde *, struct tItem *);
int mostrar(struct tItem *);
struct tItem * remover(struct tLdde *, int);
