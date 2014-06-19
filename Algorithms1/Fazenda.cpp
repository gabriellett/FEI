#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    float he,hf,hs;
    scanf("%f",&he);
    hf = (43.6*he)/109.2;
    hs = he-hf;
    printf("soja %f, feijão %f",hs,hf);
    system("PAUSE");
    return EXIT_SUCCESS;
}
