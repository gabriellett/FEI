#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int altp,basp,lquad,qtd, arplac,arquad;
    bool rest = 0;
    rest = 0;
    printf("Digite a altura da placa: \n");
    scanf("%d", &altp);
    printf("Digite o tamanho da base da placa: \n");
    scanf("%d", &basp);
    printf("Digite o lado do quadrado: \n");
    scanf("%d", &lquad);
    arplac = altp*basp;
    arquad = lquad*lquad;
    qtd = arplac/arquad;
    printf("\n \n A placa com area de %d comportara %d quadrado(s) com area de %d e \n",arplac,qtd,arquad);
    if (arplac%arquad != 0){rest=1;}
    if (rest==1){printf("possuiu resto de %d. \n",arplac%arquad);}
    else
    {printf("nao possiu resto. \n");}
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
