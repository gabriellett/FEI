#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main(int argc, char *argv[])
{
  float x1p1,y1p1,x2p2,y2p2,distancia;
  printf("Digite a coord. x1 do ponto P1:");
  scanf("%f",&x1p1);
  
  printf("Digite a coord. y1 do ponto P1:"); 
  scanf("%f",&y1p1);   
   
  printf("Digite a coord. x2 do ponto P2:");
  scanf("%f",&x2p2);  
  
  printf("Digite a coord. y2 do ponto P2:");  
  scanf("%f",&y2p2);
    
  distancia = sqrt(((x2p2-x1p1)*(x2p2-x1p1))+((y2p2-y1p1)*(y2p2-y1p1)));
  
  printf("A distancia entre os pontos P1(%.2f,%.2f) e P2(%.2f,%.2f) e' de:%.2f\n",x1p1,y1p1,x2p2,y2p2,distancia);
  system("PAUSE");	
  return 0;
}
