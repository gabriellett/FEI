#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    float mun,est,fed;
    printf("Digite os recursos fornecidos pelo municipio \n");
    scanf("%f",&mun);
    printf("\n Digite os recursos fornecidos pelo estado \n");
    scanf("%f",&est);
    printf("\n Digite os recursos federais \n");
    scanf("%f",&fed);
    float tot,pmun,pest,pfed;
    tot=mun+est+fed;
    pmun = mun*100/tot;
    pest = est*100/tot;
    pfed = fed*100/tot;
    
    printf("\n A porcentagem de recursos municipais é de %f porcento, estaduais %f porcento e %f porcento federais",pmun,pest,pfed);
    system("PAUSE");
    return EXIT_SUCCESS;
}
