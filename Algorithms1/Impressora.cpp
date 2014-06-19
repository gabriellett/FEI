#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int seg,min,hora,npag;
    printf("Digite o numero de paginas a serem impressas \n");
    scanf("%d",&npag);
    seg = npag*12;
    min = seg/60;
    seg = seg%60;
    hora = min/60;
    min = min%60;
    printf("\n A impressora demorara %d hora(s), %d minuto(s) e %d segundo(s). \n",hora,min,seg);
    system("PAUSE");
    return EXIT_SUCCESS;
}
