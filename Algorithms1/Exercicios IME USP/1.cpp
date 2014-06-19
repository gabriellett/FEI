#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int numero;
    printf("Digite uma sequencia de números inteiros seguidos de 0\n ");
    scanf("%d",&numero);
    while (numero != 0 )
    {
          
          printf("%d^2 = %d",numero,numero*numero);
              printf("\n Digite uma sequencia de números inteiros seguidos de 0\n");
    scanf("%d",&numero);
          }
    return EXIT_SUCCESS;
}
