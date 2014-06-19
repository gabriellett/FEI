#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int senha;
    int a,b,c;
    printf("Digite a senha");
    scanf("%d",&senha);
    if (senha >=1111 && senha <=9999);
    {
        a = senha % 10;
        b = (senha/10)%10;
        c = (senha/100)%10;
        if (a*b*c == 0)
        {
            printf("\n Senha invalida!");
        }
        else
        {
            printf("\n Senha Valida!");
        }
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
