#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    int n=-1;
    int cont = 0;
    while (n<0)
    {
          printf("Digite um número positivo");
          scanf("%d",&n);
    }
    if(n % 2 == 0)
    {  
       n=n-1;
    }
    while(n>cont)
    {
       printf("\n%d",n);
       n=n-2;
    }
          
        system("PAUSE");
    return EXIT_SUCCESS;
}
