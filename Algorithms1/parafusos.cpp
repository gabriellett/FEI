#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int parafusos,cxgrande,cxpequena,sobraparafusos;
    printf("digite a quantidade de parafusos \n");
    scanf ("%d",&parafusos);
    cxgrande=parafusos/40;
    sobraparafusos=parafusos%40;
    cxpequena=sobraparafusos/10;
    sobraparafusos=sobraparafusos%10;
    printf("\n Os %d parafusos couberam em %d caixa(s) grande(s) e %d caixa(s) pequena(s). Sobraram %d parafusos \n",parafusos,cxgrande,cxpequena,sobraparafusos);


    
    system("PAUSE");
    return EXIT_SUCCESS;
}
