#include "FilaEstaticaCircularPlusPlus.h"

FilaCircular::FilaCircular(void)
{
    this->setInicio(0);
    this->setFim(0);
}

void FilaCircular::setItens(int indice, int item)
{
    this->itens[indice] = item;
}

void FilaCircular::setInicio(int inicio)
{
    this->inicio = inicio;
}

void FilaCircular::setFim(int fim)
{
    this->fim = fim;
}

int FilaCircular::getItens(int indice)
{
    return this->itens[indice];
}

int FilaCircular::getInicio(void)
{
    return this->inicio;
}

int FilaCircular::getFim(void)
{
    return this->fim;
}

bool FilaCircular::isFull(void)
{
    return (this->getFim()+1)%TAMANHO == this->getInicio();
}

bool FilaCircular::isEmpty(void)
{
    return this->getInicio() == this->getFim();
}

void FilaCircular::enfileirar(int item)
{
    if(!this->isFull())
    {
        this->setItens(this->getFim(), item);
        this->setFim((this->getFim()+1)%TAMANHO);
    }
}

int FilaCircular::desenfileirar(void)
{
    int removido = this->getItens(this->getInicio());
    if(!this->isEmpty())
    {
        this->setInicio((this->getInicio()+1)%TAMANHO);
        return removido;
    }
}

void FilaCircular::mostrar(void)
{
    int i, q=0;
    system("cls");
    if(!this->isEmpty())
    {
        for(i=this->getInicio(); i!=this->getFim()%TAMANHO; i=(i+1)%TAMANHO, q++)
        {
            cout << this->getItens(i) << " ";
        }
    }
    cout << "\nA fila possui " << q << " itens" << endl;
    system("pause > NULL");
}

int Menu::show(void)
{
    int opc;
    system("cls");
    cout << "============ FILA ESTATICA CIRCULAR ============" << endl;
    cout << "       Escolha uma das opcoes a seguir:" << endl;
    cout << "               1 - Enfileirar " << endl;
    cout << "               2 - Desenfileirar " << endl;
    cout << "               3 - Mostrar Fila " << endl;
    cout << "               4 - Sair" << endl;
    cin >> opc;
    if(opc < 1 || opc > 4)
    {
        cout << "Opcao" << opc << " invalida.\nEscolha uma opocao valida" << endl;
        system("pause > NULL");
        return Menu::show();
    }
    return opc;
}
