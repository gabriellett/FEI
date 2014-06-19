#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int dia, discos,diam,discosm;
    dia = 1;
    discosm = 0;
    while(dia<30)
    {
         printf("Digite o numero de discos vendidos dia %d\n",dia);
         scanf("%d",&discos);
         if (discos>discosm)
         {
           discosm=discos;
           diam = dia;                 
         }  
         dia=dia+1;                       
    }
    printf("\n O maior numero de discos foi vendido no dia %d, uma quantidade de %d discos",diam,discosm);
    system("PAUSE");
    return EXIT_SUCCESS;
}
