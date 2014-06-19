#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int q,ad,rn,jv,data,total;
  rn=1;
  ad=0;
  jv=0;
  data=0;
  total=0;
  printf("Digite o numero de casais a serem atingidos \n");
  scanf("%d",&q);
  while(total<q)
  {
          data++;
          ad = ad + jv;
          jv = rn;
          rn = ad; 
          printf("\n Ad : %d jv: %d rn: %d",ad,jv,rn);
          total = jv+ad+rn; 
  }
  printf("\n %d",data);
  system("PAUSE");	
  return 0;
}
