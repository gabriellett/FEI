#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n,q;
    printf("Digite uma sequencia de numeros e quando desejar fechar o programa digite 0 \n");
    scanf("%d",&n);
    while (n!=0)
    {
    q=n*n;
    printf("%d ^2 = %d \n", n,q);
        scanf("%d",&n);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
