#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n=0;
    while (n<=0){
          printf("Digite a quantidade de numeros para serem \nexibidos da sequencia de Fibionacci (n!=0):");
          scanf("%d",&n);   
    }
    int ant,atu;
    atu = 0;
    ant = 1;
    int 
    res = 0;
    int aux = 0;
    system("cls");
    printf("====================== Sequencia Fibonacci de %d numeros ======================\n",n);
    while (aux<n){
        printf("\n%d: %d",aux+1,res);
        if (aux >=1){
            ant = atu;
        }

        atu = res;
        res = res + ant;
        aux++;

    }
    printf("\n\n================================================================================\n",n);
    system("PAUSE");
    return EXIT_SUCCESS;
}
