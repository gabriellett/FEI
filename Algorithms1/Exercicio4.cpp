#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    /*“Conhecendo-se os valores correspondentes a dia, mês e ano de
uma data, como determinar a quantidade de dias entre esta data e o
final do mês dessa mesma data?”
Observações:
- um ano é bissexto se for múltiplo de 4 mas não de 100,
ou se for múltiplo de 400;
- fevereiro tem 29 ou 28 dias conforme o ano seja bissexto ou não;
- janeiro, março, maio, julho, agosto, outubro e dezembro têm 31 dias;
- abril, junho, setembro e novembro têm 30 dias.*/
    int dia,mes,ano, diasRestantes;
    printf ("\tInsira uma data\n");
    printf ("Qual o dia: ");
    scanf ("%d", &dia);
    printf ("Qual o mes (numero): ");
    scanf ("%d", &mes);
    printf ("Qual o ano (4 algarismos): ");
    scanf ("%d", &ano);
    //Coloca a condição de que os meses citados possuem no máximo 31 dias
    if (mes == (1 || 3 || 5 || 7 || 8 || 10 || 12) && dia>31){
            printf ("Dia invalido!\n");
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
    diasRestantes=31-dia;
    printf ("Faltam %d dias para terminar o mes\n", diasRestantes);
    }
    //Coloca a condição de que os meses citados possuem no máximo 30 dias
    if (mes == (4 || 6 || 9 || 11) && dia>30){
            printf ("Dia invalido!\n");
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
    diasRestantes=30-dia;
    printf ("Faltam %d dias para terminar o mes\n", diasRestantes);
    }
    //Caso específico para o mês de Fevereiro
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
                      printf ("Eh o ultimo dia do mes!\n");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
