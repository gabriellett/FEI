#include <iostream>
#include <cstdlib>

using namespace std;

const int TAMANHO = 10;

class FilaCircular
{
    private:
            int itens[TAMANHO];
            int inicio, fim;
    public:
            FilaCircular(void);
            void setItens(int, int);
            void setInicio(int);
            void setFim(int);
            int getItens(int);
            int getInicio(void);
            int getFim(void);
            bool isFull(void);
            bool isEmpty(void);
            void enfileirar(int);
            int desenfileirar(void);
            void mostrar(void);
};

class Menu
{
    public: static int show(void);
};
