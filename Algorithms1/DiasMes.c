#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int dia,mes,ano, diasRestantes;
    printf ("\tInsira uma data\n");
    printf ("Qual o dia: ");
    scanf ("%d", &dia);
    printf ("Qual o mes (numero): ");
    scanf ("%d", &mes);
    printf ("Qual o ano (4 algarismos): ");
    scanf ("%d", &ano);

    if (mes == (1 || 3 || 5 || 7 || 8 || 10 || 12) && dia>31)
    {
            printf ("Dia invalido!\n");
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
    diasRestantes=31-dia;
    printf ("Faltam %d dias para terminar o mes\n", diasRestantes);
    }

    if (mes == (4 || 6 || 9 || 11) && dia>30)
    {
            printf ("Dia invalido!\n");
    }
    
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
    diasRestantes=30-dia;
    printf ("Faltam %d dias para terminar o mes\n", diasRestantes);
    }

    int bissexto=0;
    if (ano%4 == 0){
              bissexto=1;
    }
    if (mes == 2){
            if (bissexto == 1 && dia<=29){
                         diasRestantes=29-dia;
                         printf ("Faltam %d dias para terminar o mes\n", diasRestantes);
            }
            else{
                 if (mes == 2 && dia>29){
                         printf ("Dia invalido!\n");
                 }
            }
            if (bissexto != 1 && dia<=28){
                 diasRestantes=28-dia;
                 printf ("Faltam %d dias para terminar o mes\n", diasRestantes);
            }
            else{
                 if (mes == 2 && dia>28){
                         printf ("Dia invalido!\n");
                 }
            }
    }
    if (diasRestantes == 0){
                      printf ("e e' o ultimo dia do mes!\n");
    }
  system("PAUSE");	
  return 0;
}
