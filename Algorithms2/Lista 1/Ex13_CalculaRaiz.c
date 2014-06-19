#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    float a,b,c,raiz1,raiz2,delta;
    printf("Digite o coeficiente \"a\" da equacao de segundo grau:");
    scanf("%f",&a);
    printf("Digite o coeficiente \"b\" da equacao de segundo grau:");
    scanf("%f",&b);
    printf("Digite o coeficiente \"c\" da equacao de segundo grau:");
    scanf("%f",&c);
    
    delta = (b*b) - 4*a*c;
    printf("\nEquacao: %.2f * x^2 + (%.2f) * x + (%.2f)\n",a,b,c);
    if (delta<0){
         printf("A equacao nao possui raizes pertencentes ao grupo dos numeros reais \n(delta negativo)!\n"); 

    }
    if (delta==0){
         raiz1 = -b/(2*a);
         printf("A equacao possui duas raizes iguais de valor %2.f\n",raiz1);
    
    }
    if (delta>0){
         raiz1 = (-b-sqrt(delta))/(2*a);
         raiz2 = (-b+sqrt(delta))/(2*a);
         printf("As raizes da equacao sao %.2f e %.2f\n",raiz1,raiz2);
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;      
}
