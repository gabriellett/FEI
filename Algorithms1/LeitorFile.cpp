#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream filein;
	filein.open("wordlist.txt");
	string test,final1;
	while (!filein.eof()) 
    {
    getline(filein,test);
	test = test+ " ";
    cout<<test;
    final1 = final1+test;
	}
	filein.close();
	//cout<<"\n"<<final1;
	
	

	string palavras[9];
	string aux;
	string nova;
	int pos = nova.find(" ");
	aux=nova;
	string palavra = "dd1vai";
	palavras[0]="yra1lr";
	palavras[1]="ymsitp";
	palavras[2]="dd1vai";
	palavras[3]="poleep";
	palavras[4]="srodaenn";
	palavras[5]="hpzdao";
	palavras[6]="rfened";
	//palavras[7]="tenpaar";
	palavras[7]="darnea";
	//palavras[9]="znneasu";
	string final,letra;
	int c=0;

	while (c<8)
	{
        nova =  final1;
        int pos = nova.find(" ");
	    aux=nova;
	    printf("%d",c);
        palavra = palavras[c];
    	while (palavra.length()>=1)
    	{
    	letra = palavra.substr(0,1);
    	//cout<<" "<<letra;
    	pos = aux.find(" ");
    		if(pos<nova.find(letra))
    		{
    	    //cout<<"IN IF";
    			do
    			{
    				do
    				{
    					aux.erase(0,pos);
    					pos = aux.find(" ")+1;

    				}
    				while (aux.find(" ")<aux.find(letra));
    				pos = aux.find(" ");
    				if (pos>aux.length() && aux.find(letra) < aux.length())
    				{
    					final = final+aux;
    					aux = "";
    					pos = aux.find(" ");

    				}
    				else
    				{
    					final = final + " " + aux.substr(0,pos);
    					aux.erase(0,pos);
    					pos = aux.find(" ");

    				}
    			}
    			while (pos<aux.find(letra));
    			nova = final;
    			aux = nova;
    			final.erase(0,1);
    			if(palavra.length()>1)
    			{
    				final = "";
    			}
    	
    		}
    	
    	palavra.erase(0,1);
    	}
    	final.erase(final.length()-1,1);

        int naoachou=1;
    	while(final.find(" ")<final.length())
    	{
        
              cout<<"\n \n-"<<final<<"-\n";
     
              string palavratu = final.substr(0,final.find(" ")-1);
              final.erase(0,1);
              string palavratuaux = palavratu;
              final.erase(0,final.find(" ")+1);
              int tamproc = palavras[c].length();
              int letu=0;
              string letras[tamproc];
              if (palavratu.length()>palavras[c].length())
              {naoachou=0;}
              else{
              while (letu<tamproc)
              {
                    letras[letu] = palavras[c].substr(letu,1);
                    //cout<<"\n LETRATU:"<<letras[letu];
                    letu++;
              }   
              letu=0;

              while (palavratuaux.length()>0 && naoachou==1) 
              {
                    
                    int posachada = palavratuaux.find(letras[letu]);
                    int tamaux = palavratuaux.length();
                    cout<<"\n palavratuaux:"<<palavratuaux<<"-letra:"<<letra[letu]<<"posfind:"<<palavratuaux.find(letras[letu])<<"-";
                    if(posachada<0)
                    {        
                        //cout<<"\n OI:"<<naoachou;           
                        naoachou=0;
                    }
                    else
                    {
                        palavratuaux.erase(posachada,1);
                        
                    }
              } 
              if (naoachou==1)
              {
               final = final + palavratu;
              }
              }
        }
    	//cout<<"\n-"<<final<<"-\n ";
        /*	while(final.find(" ")<final.length())
    	{
             //cout<<"\n-"<<final<<"-\n ";
             int bra;
             bra = final.find(" ");
             //printf("%d",palavras[c].length());
             string palcomp = final.substr(0,bra);  
             final.erase(0,bra+1);
             //cout<<"-"<<palcomp<<"-";
             int woo=palcomp.length();
             if(palavras[c].length()==palcomp.length())
             {
                  string charcomp[palcomp.length()];
                  cout<<"palcomp:"<<palcomp;
                  while (woo>0)
                  {
                        charcomp[woo-1]=palcomp.substr(0,1);
                        palcomp.erase(0,1);
                        cout<<"\n woo:"<<woo-1<<charcomp[woo-1];
                        woo=woo-1;
                  }
                  woo=0;
                  int naoach=1;
                  string palavraaux = palavras[c];
                  cout<<"\n woo:"<<woo<<charcomp[0];
                  int cont=1;
                  while(woo<palavras[c].length()-1 && cont == 1)
                  {
                     if (palavras[c].find(charcomp[woo])> palavras[c].length())
                     {        
                     naoach=0;
                     cont=0;
                     cout<<"\n "<<palavras[c]<<"com:"<<charcomp[woo];
                     cout<<"\n NAO ACHOU :)\n";
                     }
                     else
                     {
                     palavraaux.erase(palavras[c].find(charcomp[woo]),1);
                     }
                     cout<<"\n woo:"<<charcomp[woo]<<"-palaux:"<<palavraaux<<"-palavra:"<<palavras[c]; 
                     woo++;
                     //cout<<"\nAQUI:"<<charcomp[woo]; 
                     
                  }
                  if(naoach==1)
                  {
                  final = palcomp;
                  }

                  cout<<"\n-"<<final<<"-\n ";
             }   
             //cout<<"\n";
             //system("PAUSE");      
        }
        */
    	cout<<"\n-"<<final<<"-\n ";
    	c++;
    }
    

	
    system("PAUSE");
    return EXIT_SUCCESS;
}
