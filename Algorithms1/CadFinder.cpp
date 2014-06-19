#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    string frase;// = "Ain Sain Manin int denin";
    string fraseaux;
    printf("Digite a frase \n");
    getline(cin, frase);
    
    string cad;// = "in";
    int pos,tamcad;
    int ocorr=0;

    printf("Digite a cadeia a ser encontrada \n");
    getline(cin,cad);
    //cad = "in";

    
    //Remove os espacos em branco:
    
    printf("Frase sem os epacos em branco desnecessarios:\n");
    string branco = " ";
    pos = 0;
    while(pos == 0)
    {
              if (frase.find(branco) == 0 )
              {
                 frase.erase(0,1);
              }
              pos = frase.find(branco);
    }

    cout<<"Frase: ''"<<frase<<"''";
    
    //Remove a cadeia escolhida
    printf("Remomcao da cadeia escolhida:\n");
    tamcad = cad.length();
    pos = frase.find(cad);
    fraseaux = frase;
    while ( pos < fraseaux.length())
    {
        fraseaux.erase(pos,tamcad);
        ocorr++;
        //cout<<frase<<","<<pos<<","<<ocorr<<"\n";
        pos = fraseaux.find(cad);
    }
    printf("\nA quantidade de ocorrencias da cadeia na frase e de %d vezes \n",ocorr);
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
    
}
