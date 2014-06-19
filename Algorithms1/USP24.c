#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int p,q;
  int paux,qaux,pqtd;
  int tamp = 1;
  int tamq = 1;
  int aux;
  int div=1;
  int ok=0;
  printf("Digite o valor de p\n");
  scanf("%d",&p);
  printf("Digite o valor de q\n");
  scanf("%d",&q);
  if (p>q)
  {
          printf("\n Numeros invaldos, p deve ser maior que q \n");
  }
  else
  {
      
  qaux = q/10;
  paux = p/10;
            printf("\n %d", q);
  printf("\n %d,%d",qaux,tamp);
  while (qaux != 0)
  {
        tamq++;
        qaux = qaux/10;
  }
          printf("\n %d", q);
    while (paux != 0)
  {
        tamp++;
        paux = paux/10;
  }
          printf("\n %d", q);
  while (tamp >0)
  {
        div = div*10;
        tamp = tamp - 1;
  }
          printf("\n %d", q);
    printf("\n %d,%d",tamp,tamq);
    aux = q % div;
    printf("\n %d",aux);
    while (aux>0)
    {
          printf("\n %d, %d", aux, q);
          if (aux== p)
          {
          ok=1;
          }
    q = q/10;
    aux = q% div;

    }

        if (ok==1)
        {
          printf("\n \n \n O numero p e subnumero de q \n");         
        }
        else
        {
            printf("\n O numero p nao e subnumero de q \n");
        }
}
  system("PAUSE");	
  return 0;
}
