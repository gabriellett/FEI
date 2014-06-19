#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotacao=0;

struct No
{
    int chave;
    struct No *esquerda;
    struct No *direita;
    struct No *pai;
};

struct Arvore
{
    struct No *raiz;
};

struct Arvore *criaArvore()
{
    struct Arvore *aux = (struct Arvore*) malloc(sizeof(struct Arvore));
    if(aux != NULL)
    {
        aux->raiz = NULL;
    }
}

struct No *criaNo(int *chave)
{
    struct No *aux = (struct No*) malloc(sizeof(struct No));
    if(aux != NULL)
    {
        aux->chave = *chave;
        aux->esquerda = NULL;
        aux->direita = NULL;
        aux->pai = NULL;
    }
}

int fatorBalanceamento(struct No *raiz)
{
    if(raiz!=NULL)
    {
        return altura(raiz->esquerda) - altura(raiz->direita);
    }
    return 0;
}

void rotacaoEsquerda(struct No *r, struct Arvore *t)
{
    struct No *p = r->pai;
    struct No *d = r->direita;
    struct No *beta = d->esquerda;

    if(p!=NULL)
    {
        if(p->esquerda == r)
        {
            p->esquerda = d;
        }
        else
        {
            p->direita = d;
        }
        d->pai = p;
    }
    else
    {
        t->raiz = d;
        d->pai = NULL;
    }

    d->esquerda = r;
    r->pai = d;
    r->direita = beta;
    if(beta!=NULL)
    {
        beta->pai = r;
    }
    rotacao++;
}

void rotacaoDireita(struct No *r, struct Arvore *t)
{
    struct No *p = r->pai;
    struct No *e = r->esquerda;
    struct No *beta = e->direita;

    if(p!=NULL)
    {
        if(p->esquerda == r)
        {
            p->esquerda = e;
        }
        else
        {
            p->direita = e;
        }
        e->pai = p;
    }
    else
    {
        t->raiz = e;
        e->pai = NULL;
    }
    e->direita = r;
    r->pai = e;
    r->esquerda = beta;
    if(beta!=NULL)
    {
        beta->pai = r;
    }
    
    rotacao++;
}

void balancearAVL(struct No *r, struct Arvore *t)
{
    int fatorR = fatorBalanceamento(r);
    int fatorE = fatorBalanceamento(r->esquerda);
    int fatorD = fatorBalanceamento(r->direita);

    if(fatorR == -2)
    {
        if(fatorD == 1)
        {
            rotacaoDireita(r->direita, t);
        }
        rotacaoEsquerda(r, t);
    }
    else if(fatorR == 2)
    {
        if(fatorE == -1)
        {
            rotacaoEsquerda(r->esquerda, t);
        }
        rotacaoDireita(r, t);
    }

    if(r->pai != NULL)
    {
        balancearAVL(r->pai, t);
    }
}


void inserir(struct Arvore *t, struct No *novo)
{
    struct No *pai=NULL, *filho=t->raiz;
    if(t->raiz == NULL)
    {
        t->raiz = novo;
    }
    else
    {
        while(filho!=NULL)
        {
            pai = filho;
            if(filho->chave > novo->chave)
            {
                filho = filho->esquerda;
            }
            else
            {
                filho = filho->direita;
            }
        }
        if(pai->chave > novo->chave)
        {
            pai->esquerda = novo;
        }
        else
        {
            pai->direita = novo;
        }
        novo->pai = pai;
        balancearAVL(novo->pai, t);
    }
}

void removera(struct Arvore *t, int chave)
{
    struct No *pai=NULL, *filho=t->raiz, *subs_pai=NULL, *subs;
    if(t->raiz!=NULL)
    {
        while(filho!=NULL && filho->chave != chave)
        {
            pai = filho;
            
            if(filho->chave > chave)
            {
                filho = filho->esquerda;
            }
            
            else
            {
                filho = filho->direita;
            }
        }
        if(filho!=NULL)
        {
            if(filho->esquerda == NULL && filho->direita == NULL)
            {
                if(pai!=NULL)
                {
                    if(pai->esquerda == filho)
                    {
                        pai->esquerda = NULL;
                    }
                    else
                    {
                        pai->direita = NULL;
                    }
                }
                else
                {
                    t->raiz = NULL;
                }
            }
            else if(filho->esquerda != NULL && filho->direita != NULL)
            {
                subs = filho->esquerda;
                while(subs!=NULL)
                {
                    subs_pai = subs;
                    subs = subs->direita;
                }
                subs = (struct No*) malloc(sizeof(struct No));
                subs->chave = subs_pai->chave;
                subs->esquerda = subs->direita = NULL;
                removera(t, subs_pai->chave);
                if(pai != NULL)
                {
                    if(pai->esquerda == filho)
                    {
                        pai->esquerda = subs;
                    }
                    else
                    {
                        pai->direita = subs;
                    }
                }
                else
                {
                    t->raiz = subs;
                }
                subs->direita = filho->direita;
                if(filho->direita != NULL)
                    filho->direita->pai = subs;
                subs->esquerda = filho->esquerda;
                if(filho->esquerda != NULL)
                    filho->esquerda->pai = subs;
                subs->pai = pai;
            }
            else
            {
                if(pai != NULL)
                {
                    if(pai->esquerda == filho)
                    {
                        if(filho->esquerda != NULL)
                        {
                            pai->esquerda = filho->esquerda;
                            filho->esquerda->pai = pai;
                        }
                        else
                        {
                            pai->esquerda = filho->direita;
                            filho->direita->pai = pai;
                        }
                    }
                    else
                    {
                        if(filho->esquerda != NULL)
                        {
                            pai->direita = filho->esquerda;
                            filho->esquerda->pai = pai;
                        }
                        else
                        {
                            pai->direita = filho->direita;
                            filho->direita->pai = pai;
                        }
                    }
                }
                else
                {
                    if(filho->esquerda != NULL)
                    {
                        t->raiz = filho->esquerda;
                        filho->esquerda->pai = NULL;
                    }
                    else
                    {
                        t->raiz = filho->direita;
                        filho->direita->pai = NULL;
                    }
                }
            }
            balancearAVL(filho->pai,t);
            free(filho);
        }
    }
}

void preOrdem(struct No *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(struct No *no)
{
     if (no != NULL)
     {
            posOrdem(no->esquerda);
            posOrdem(no->direita);
            printf("%d ", no->chave);
     }
}

void inOrdem(struct No *raiz)
{
    if(raiz != NULL)
    {
        inOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        inOrdem(raiz->direita);
    }
}

int altura(struct No *raiz)
{
    int d=0, e=0;

    if (raiz == NULL)
       return -1;

    else
    {
       e = altura(raiz->esquerda);
       d = altura(raiz->direita);

       if (e < d)
         return d + 1;

       else
         return e + 1;
    }
}

int main()
{
    struct Arvore *t = criaArvore();
    int num;
    char c[5];

    gets(c);

    while(scanf("%d", &num) != EOF)
        inserir(t, criaNo(&num));

    if(strcmp(c, "POS") == 0)
        posOrdem(t->raiz);

    else if(strcmp(c, "PRE") == 0)
        preOrdem(t->raiz);

    else
        inOrdem(t->raiz);

    printf("%d", altura(t->raiz));
    
    printf(" %d", rotacao);
    
}

