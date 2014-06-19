//Danielle Santos    
//Gabriel Lett 	     
//Maryelle Sousa    


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char alfabeto[255];
int numEstados;
int numEstadosFinais;
int estadoInicial;
int * estadosFinais;
int ** resultados;
int isGoto;

struct funcao{
    int estadoIn;
    char simb;
    int estadoOut;
};

void writeCodigo();

int firstIndexOf(char * str, char ele){
    int i = 0;
    while(str[i] != 0){
        if(str[i] == ele){
            return i;
        }
        i++;
    }
    return -1;
}

void adicionaElementoArray(struct funcao **array, int currSize){
    int tamTotal = currSize + 1;
    
    * array = (struct funcao *) realloc (* array,(tamTotal * sizeof(struct funcao)));
    
}

int main(int argc, char *argv[]){

    FILE * fp;

    if((fp=fopen("aula.conf","r"))==NULL){
        printf(stderr,"Erro ao abrir o arquivo");
        exit(1);
    }

    char dummy[255];
    char sNumEstados[255];
    char sEstadoInit[255];
    char sNumEstadosFinais[255];
    int i;


    fgets(dummy,255,fp);
    fgets(alfabeto,255,fp);
    //fprintf(fw, "Alfabeto: %s",alfabeto);
    fgets(dummy,255,fp);
    fgets(sNumEstados,255,fp);
    numEstados = atoi(sNumEstados);
    //fprintf(fw, "Numero de estados: %d\n",numEstados);
    fgets(dummy,255,fp);
    fgets(sEstadoInit,255,fp);
    estadoInicial = atoi(sEstadoInit);
    //fprintf(fw, "Estado inicial: %d\n",estadoInicial);
    fgets(dummy,255,fp);
    fgets(sNumEstadosFinais,255,fp);
    numEstadosFinais = atoi(sNumEstadosFinais);
    //fprintf(fw, "Numero de estados finais: %d\n",numEstadosFinais);

    estadosFinais = malloc(sizeof(int)*numEstadosFinais);
        fgets(dummy,255,fp);

    for(i=0; i<numEstadosFinais;i++){
        fgets(dummy,255,fp);
        estadosFinais[i] = atoi(dummy);
        //fprintf(fw, "Estado Final %d : %d \n", i, estadosFinais[i]);
    }

    int tamanhoAlfabeto = strlen(alfabeto)-1;
    
    resultados = (int**) malloc(numEstados * sizeof(int*));
    for(i=0; i< numEstados; i++){
        resultados[i] = (int*) malloc(tamanhoAlfabeto * sizeof(int));
    }
    struct funcao * funcoes = NULL;
    
    fgets(dummy,255,fp);
    i=1;
    while(1){
        
    
        fgets(dummy,255,fp);
        printf("%s",dummy);
        if(strcmp(dummy,"FIM\n")==0) break;
        
        if(funcoes == NULL){
            funcoes = malloc(sizeof(struct funcao));
        }else{
            adicionaElementoArray(&funcoes,++i);
        }
        
        int wordLen = firstIndexOf(dummy, ',');
        
        char * substr  = malloc(sizeof(char)*wordLen);
        memcpy( substr, &dummy[0], wordLen);
        memcpy( dummy, &dummy[wordLen+1], strlen(dummy));
        substr[wordLen] = 0;
        funcoes[i-1].estadoIn = atoi(substr);
        wordLen = firstIndexOf(dummy, ',');
        
        memcpy( substr, &dummy[0], wordLen);
        memcpy( dummy, &dummy[wordLen+1], strlen(dummy));
        substr[wordLen] = 0;
        funcoes[i-1].simb = substr[0];
        funcoes[i-1].estadoOut = atoi(dummy);
        
        //printf(" \n %d + %c = %d", funcoes[i-1].estadoIn, funcoes[i-1].simb, funcoes[i-1].estadoOut);
       
        resultados[funcoes[i-1].estadoIn][firstIndexOf(alfabeto,funcoes[i-1].simb)] = funcoes[i-1].estadoOut;
    }
    
    fgets(dummy,255,fp);
    fgets(dummy,255,fp);
    
    isGoto = atoi(dummy);
    // Inicia impressao codigo:
    writeCodigo();        
    //system("PAUSE");

    exit(0);
}

void writeCodigo(){
    int i;
    int tamanhoAlfabeto = strlen(alfabeto)-1;
    
    FILE *fw = fopen("programaGerado.c","w");
    if(fw==NULL){
        fprintf(fw, "Erro ao criar o arquivo!");
        exit(1);
    }
    
    fprintf(fw, "#include <stdio.h>\n");
    fprintf(fw, "#include <stdlib.h>\n\n");
    if(!isGoto){
        fprintf(fw, "void aceito();\nvoid rejeitado();\n");
    
        for(i=0; i<numEstados;i++){
            fprintf(fw, "void e%d();\n",i);    
        }
    
        fprintf(fw, "\nint p;\n");
        fprintf(fw, "char f[200];\n\n");
    }   

    fprintf(fw, "int main(){\n");
    if(isGoto){    
        fprintf(fw, "   \nint p = 0;\n");
        fprintf(fw, "   char f[200];\n\n");
    }else{
        fprintf(fw, "    p=0;\n");
    }
    
    fprintf(fw, "    printf(\"Linha?\\n\");\n");
    fprintf(fw, "    gets(f);\n");
    
    if(!isGoto){
        fprintf(fw, "    e%d();\n",estadoInicial);
        fprintf(fw, "    return (0);\n");    
        fprintf(fw, "}");
    }
    
    printf("\n\n");
    
    int k;
    
    for(i=0; i<numEstados;i++){
        if(!isGoto){
            fprintf(fw, "\nvoid e%d(){\n",i);
        }else{
            fprintf(fw, "\nE%d:\n",i);
        }
        
        int numRejeitados = 0;
        int numAceitos = 0;
        for(k=0; k<tamanhoAlfabeto;k++){
            if(resultados[i][k]>-1){
                numAceitos++;
                if(numAceitos==1){
                    fprintf(fw, "    if(f[p]=='%c'){\n",alfabeto[k]);
                }else{
                    fprintf(fw, "    } else if(f[p]=='%c'){\n",alfabeto[k]);
                
                }
                fprintf(fw, "       p++;\n");
                if(isGoto){
                    fprintf(fw, "       goto E%d;\n",resultados[i][k]);
                }else{
                    fprintf(fw, "        e%d();\n",resultados[i][k]);
                }
            }else{
                numRejeitados++;
            }
            
            
        }
        int isFinal = 0;
            int l;
            for(l=0; l< numEstadosFinais; l++){
                if(estadosFinais[l] == i){
                    isFinal=1;
                }
            }
            
            if(isFinal){
                if(numAceitos > 0){
                    fprintf(fw, "    }else if(f[p]==0){\n");                
                }else{
                    fprintf(fw, "    if(f[p]==0){\n");                
                }    
                if(isGoto){
                    fprintf(fw, "       goto ACE;");
                }else{
                    fprintf(fw, "       aceito();\n");
                }
            }
            
            if(numRejeitados == 0){
                fprintf(fw, "    }\n");
            }else{
                fprintf(fw, "    }else{\n");
                if(isGoto){
                    fprintf(fw, "       goto REJ;");
                }else{
                    fprintf(fw, "       rejeitado();\n");
                }
                fprintf(fw, "    }\n");
            }
            
        if(!isGoto) fprintf(fw, "}");
        
        fprintf(fw, "\n");
    }
    
    if(isGoto){
        fprintf(fw, "\nACE:\n");
    }else{
        fprintf(fw, "\nvoid aceito(){\n");
    }
    fprintf(fw, "    printf(\"\\n\\nAceito\\n\\n\");\n");
    fprintf(fw, "    getch();\n");
    fprintf(fw, "    exit(1);\n");
    if(!isGoto) fprintf(fw, "}\n");
    
    if(isGoto){
        fprintf(fw, "\nREJ:\n");
    }else{
        fprintf(fw, "\nvoid rejeitado(){\n");
    }
    
    fprintf(fw, "    printf(\"\\n\\nRejeitado\\n\\n\");\n");
    fprintf(fw, "    getch();\n");
    fprintf(fw, "    exit(1);\n");
    
    if(!isGoto) fprintf(fw, "}\n");
    
    if(isGoto) fprintf(fw, "\n  return 0;\n}");
    fclose(fw);
}
