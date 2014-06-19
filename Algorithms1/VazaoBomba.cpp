#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int vaz,cap,seg,min,hor,tots;
    printf("Digite a capacidade do tanque em Litros: \n");
    scanf("%d",&cap);
    printf("Digite a vazao da bomba, em litros por segundo: \n");
    scanf("%d",&vaz);
    tots = cap/vaz;
    seg = tots%60;
    min = tots/60;
    hor = min/60;
    min = min%60;
    printf("\n A bomba demorara %d hora(s), %d mintos e %d segundos. \n", hor,min,seg);
    system("PAUSE");
    return EXIT_SUCCESS;
}
