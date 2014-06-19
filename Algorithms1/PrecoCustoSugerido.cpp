#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    float pcusto,psug,pfinal;
    printf("Digite o preco de custo: \n");
    scanf("%f",&pcusto);
    pfinal= 1.15*pcusto;
    psug = 1.20*pfinal;
    printf("\n O preco final do produto será %f, e o sugerido %f \n", pfinal,psug);
    system("PAUSE");
    return EXIT_SUCCESS;
}
