#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    printf("Digite a quantidade de fichas que o jogador possui inicialmente");
    int fichainic, fichat,njog,fichajogant,fichajogantant,fichajogat;
    scanf("%d",&fichainic);
    fichat=fichainic;
    fichajogant = 5;
    fichajogantant= 2;
    fichat = fichat - 7;
    while (fichat >0)
    {
          printf(" \n %d --  At :%d , Ant: %d AntAnt: %d",njog,fichat,fichajogant,fichajogantant);
          fichajogat = fichajogant + 2*fichajogantant;
          fichat = fichat - fichajogant - 2*fichajogantant;
          fichajogantant = fichajogant;
          fichajogant = fichajogat;
          njog++;
          }
          printf("\n %d",njog);
    system("PAUSE");
    return EXIT_SUCCESS;
}
