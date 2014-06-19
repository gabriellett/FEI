#include "ldde.h"

struct tLdde * criaLista()
{
    struct tLdde *lista = (struct tLdde*) malloc(sizeof(struct tLdde));
    if(lista != NULL)
    {
        lista->primeiro = lista->ultimo = lista;
    }
    return lista;
}

struct tItem * criaItem()
{
    struct tItem *it = (struct tItem*) malloc(sizeof(struct tItem));
    if(it != NULL)
    {
        lerItem(it);
        it->anterior = it->proximo = it;
    }
    return it;
}

void lerItem(struct tItem *it)
{
    system("cls");
    printf("Informe o valor da chave: ");
    scanf("%d", &it->info.chave);
}

void inserir(struct tLdde *l, struct tItem *novo)
{
    struct tItem *atual, *anterior;
    if(l->primeiro == NULL && l->ultimo == NULL)
    {
        l->primeiro = l->ultimo = novo;
    }
    else
    {
   
    }
}

struct tItem * remover(struct tLdde *l, int chave)
{
    struct tItem *atual, *anterior;
    for(atual=l->primeiro, anterior = NULL; atual->info.chave != chave && atual!=NULL; anterior=atual, atual=atual->proximo);
    if(atual != NULL)
    {
        if(anterior == NULL)
        {

        }
        else
        {

        }
        return NULL;
    }
    else
    {
        return atual;
    }
}

int menu()
{
    int opc;
    system("cls");
    printf("-------------- LDDE --------------\n");
    printf(" Escolha uma das opcoes a seguir:\n");
    printf("            1 - Inserir\n");
    printf("            2 - Remover\n");
    printf("            3 - Mostrar\n");
    printf("            4 - Sair\n");
    printf("         ==> ");
    scanf("%d", &opc);
    if(opc < 1 || opc > 4)
    {
        printf("\nOpcao %d invalida\nEscolha uma opcao valida...\n", opc);
        system("pause");
        return menu();
    }
    return opc;
}
