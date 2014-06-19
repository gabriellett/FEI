#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int xa,ya,xb,yb;
    printf("Digite Xa \n");
    scanf("%d",&xa);
    printf("Digite Ya \n");
    scanf("%d",&ya);
    printf("Digite Xb \n");
    scanf("%d",&xb);
    printf("Digite Yb \n");
    scanf("%d",&yb);
    int bas,alt;
    if (xa<xb)
    {
    bas = xb-xa;}
    else
    {
        bas = xa-xb;
    }
    if(yb>ya){
    alt = yb-ya;}
    else
    {alt = ya-yb;}
    int per;
    per = 2*alt+2*bas;
    printf("O Perimetro do retangulo e' %d  \n",per);

    system("PAUSE");
    return EXIT_SUCCESS;
}
