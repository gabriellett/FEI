#include "FilaEstaticaCircularPlusPlus.h"

int main()
{
    FilaCircular fila;
    int escolha, item;

    do
    {
        escolha = Menu::show();
        switch(escolha)
        {
            case 1:
                    cout << "Informe o valor a ser enfileirado: ";
                    cin >> item;
                    fila.enfileirar(item);
                    break;
            case 2:
                    if(!fila.isEmpty())
                    {
                        item = fila.desenfileirar();
                        cout << "Item " << item << " desenfileirado com sucesso...";
                    }
                    else
                    {
                        cout << "Fila Vazia...";
                    }
                    system("pause > NULL");
                    break;
            case 3:
                    fila.mostrar();
        }
    }while(escolha != 4);

}
