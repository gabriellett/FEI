#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int x,n,res;
    n=-2;
    
    printf("Digite o valor de x:");
    scanf("%d",&x);
    
    while (n<0)
    {
          printf("Digite o valor de n:");
          scanf("%d",&n);
    }
    res = x;
    while (n>1)
    {
       res = res*x;
       n=n-1;
    }      
    printf("O Resultado e:%d",res);
    system("PAUSE"); 
    return EXIT_SUCCESS;
}
