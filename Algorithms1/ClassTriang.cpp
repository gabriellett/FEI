#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    float anga, angb, angc;
    printf("Digite os valores de dois dos angulos do triangulo\n");
    scanf("%f",&anga);
    scanf("%f",&angb);
    if(anga == 0 || angb == 0 || (anga+angb>=180))
    {
            printf("\nAlgum ou todos os valores digitados estão incorretos");       
    }        
    else
    {
         angc = 180 -anga -angb;
         if (anga == 90 || angb == 90 || angc == 90)
         {
                  printf("\n O terceiro angulo tem medida de %f graus, e o triangulo é retangulo",angc);
         }  
         if (anga > 90 || angb >90 || angc >90)
         {
                            printf("\n O terceiro angulo tem medida de %f graus, e o triangulo é obtusangulo",angc);         
         }  
         if (anga < 90 && anga < 90 && anga <90)
         {
                           printf("\n O terceiro angulo tem medida de %f graus, e o triangulo é acutangulo",angc);         
         }    
    }
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
