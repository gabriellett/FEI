#include <cstdlib>
#include <iostream>
#include<fstream>

using namespace std;


using namespace std;

int main(int argc, char *argv[])
    {   
    
     ifstream myReadFile;
     myReadFile.open("wordlist.txt");
     string wordlist,wordatu;
     if (myReadFile.is_open()) {
     while (!myReadFile.eof()) {
    
    
        myReadFile >> wordatu;
        wordlist=wordlist+" "+wordatu;
    
    
     }
    }
    myReadFile.close();
    
    ifstream readfile2;
     readfile2.open("tbx.txt");
     string wordatutbf;
     string wordtbf[10];
     string wordfinal[10];
     int wtbf=0;
     if (readfile2.is_open()) {
     while (!readfile2.eof()) {
    
    
        readfile2 >> wordatutbf;
        wordtbf[wtbf]=wordatutbf;
        wtbf++;
    
     }
    }

    wordlist.erase(0,1);
    cout<<"-"<<wordlist<<"-\n TBF: \n "<<wordtbf[9]<<"\n \n \n----------------------------------------------------------------------------- \n";
    readfile2.close();
    
    
    wtbf=0;
    while (wtbf<10)
    {
          
          int achoufinal=0;
          string wordlist2=wordlist;
          while (wordlist2.find(" ")<wordlist2.length() && achoufinal==0)
          {
                string wordatu = wordlist2.substr(0,wordlist2.find(" "));
                wordlist2.erase(0,wordlist2.find(" ")+1);
                string wordatuaux = wordatu;
                string wordscr = wordtbf[wtbf];
                int achou=1;
                achoufinal=0;
                while (wordatuaux.length()>0 && achou==1 && achoufinal==0)
                {
                      achou=1;
                      
                      string letratu = wordscr.substr(0,1);
                      //cout<<"\n";system("PAUSE");cout<<"\nletratu:"<<letratu<<"\nword:"<<wordatuaux;
                      wordscr.erase(0,1);
                      if (wordatuaux.find(letratu)>wordatuaux.length())
                      {
                          achou=0;
                      }
                      else
                      {
                          wordatuaux.erase(wordatuaux.find(letratu),1);
                      }
                      if (wordatuaux.length()==0)
                      {
                      //cout<<"\n";system("PAUSE");cout<<"\nletratu:"<<letratu<<"\nword:"<<wordatu;
                      //cout<<"\n OIOI\n";
                      achoufinal=1;
                      wordfinal[wtbf]=wordatu;
                      }
                }

          }
                cout<<"\n\n --------------------"<<wtbf<<"--------------------\n \n"<<"Palavra embaralhada: "<<wordtbf[wtbf]<<"\n Desembaralhada:     "<<wordfinal[wtbf];
                wtbf++;          
          
                
    }
    wtbf = 0;
    string final;
    while (wtbf<10)
    {
          final = final+","+wordfinal[wtbf];
          wtbf++;
    }
    final.erase(0,1);
        ofstream outfile;// declaration of file pointer named outfile
    outfile.open("final.txt", ios::out); // opens file named "filename" for output
    outfile << final;//saves "Hello" to the outfile with the insertion operator
    outfile.close();// closes file; always do this when you are done using the file
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
