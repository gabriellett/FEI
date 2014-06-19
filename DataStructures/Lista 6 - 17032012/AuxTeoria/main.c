#include "ldde.h"

int main(int argc, char *argv[])
{
    struct tLdde *lista = criaLista();
    int escolha, qtde, remChave;
    struct tItem *itRem;
    char resp;
    
    do
    {
        escolha = menu();
        switch(escolha)
        {
            case 1: inserir(lista, criaItem());
                    break;
            case 2: system("cls");
                    printf("Informe o valor da chave a ser removida: ");
                    scanf("%d", &remChave);
                    itRem = remover(lista, remChave);
                    if(itRem != NULL)
                    {
                        printf("\nItem chave [%d] localizado. Deseja realmente exclui-lo. [S]im [N]ao: ", remChave);
                        do
                        {
                            resp = getche();
                        }while(toupper(resp) != 'S' && toupper(resp) != 'N');
                        if(toupper(resp) == 'S')
                        {
                            free(itRem);
                            printf("\nItem chave [%d] removido com sucesso...\n", remChave);
                        }
                        else
                        {
                            inserir(lista, itRem);
                            printf("\nRemocao do item chave [%d] abortada...\n", remChave);
                        }
                        system("pause");
                    }
                    else
                    {
                        printf("O item chave [%d] nao estah na lista...\n", remChave);
                        system("pause");
                    }
                    break;
            case 3: qtde = mostrar(lista->primeiro);
                    printf("\nA lista possui %d itens...\n", qtde);
                    system("pause");
        }
    }while(escolha != 4);
    printf("Saindo...\n");
    system("pause");
}
