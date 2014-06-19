#include <cstdlib>
#include <iostream>
#include <cmath>



using namespace std;

int main(int argc, char *argv[])
{
    float cat1,cat2,hip,rai;
    printf("Digite o valor do cateto 1 do triangulo retangulo\n");
    scanf("%f",&cat1);
    printf("\nDigite o valor do cateto 2 do triangulo retangulo\n");
    scanf("%f",&cat2);
    hip = sqrt(cat1*cat1+cat2*cat2);
    rai = (cat1*cat2)/(cat1+cat2+hip);
    printf("\nO valor do raio e %f \n",rai);
    system("PAUSE");
    return EXIT_SUCCESS;
}
