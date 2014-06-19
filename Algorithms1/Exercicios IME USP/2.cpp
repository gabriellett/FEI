#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n=-1;
    int a=0;
    int res;
    while (n<0)
    {
    printf("Digite um numero positivo \n");
    scanf("%d",&n);
    
}
res=n;
while (n!=a)
{
      n=n-1;
      res = res+n;

      }
      printf("O resultado e %d",res);
    system("PAUSE");
    return EXIT_SUCCESS;
}
