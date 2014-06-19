#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani
/* Exercicio  01 - Lista de Exerc�cios 11                  */
/* CC2621 --2011    --turma 610   
/***************************  FEI  *************************/

struct sRecruta
{
       char nome[100];
       //Identifica��o: CPF?
       unsigned long int identificacao;
       int dataNascRecruta[3];
       char endereco[250];
       float altura,peso;
       int quantIrmaos;
       char nomeProge[100];
       unsigned long int identProge;
       int dataNascProge[3];


};


struct sLista
{
       struct sRecruta *itens;
       int quant;
       int valorMax;
};

int isValido(char*,int);

/* * * * * * * * * * ALISTAR * * * * * * * * * * * * * * *  */
void alistarRecruta(struct sLista *lista){
    system("cls");
    int isEncontrado=0, i=0, j=0,valido;
    struct sRecruta *novoRecruta;

    /* Se n�o estiver cheia */
    if(lista->quant < lista->valorMax){

        novoRecruta = (struct sRecruta*) malloc(sizeof(struct sRecruta));

        valido=0;
        while(!valido){
            setbuf(stdin, NULL);
            printf("Informe o nome do recruta: ");
            gets(novoRecruta->nome);
            valido=isValido(novoRecruta->nome,4);
        }


        valido=0;

        printf("Informe a identificacao do recruta: ");
        scanf("%d",&novoRecruta->identificacao);

        int ano=0,mes=0,dia=0;
        int diaInvalido = 1;

        while (ano<=0){
            printf("Digite o ano de nascimento do recruta: ");
            scanf("%d",&ano);
            if(ano>1993){
                //Caso ele nao faca 18 anos no ano atual ou nao tenha feito 18 anos:
                printf("Atencao: O recruta nao se encontra na idade de servico militar!\n");
                ano=0;
            }
        }

        while (mes<1 || mes>12){
            printf("Digite o mes de nascimento do recruta: ");
            scanf("%d",&mes);
        }
        int bissexto;
        if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ( ano % 400 == 0 ) ){
            bissexto= 1;
        }else{
            bissexto= 0;
        }

        while (diaInvalido == 1){
            printf("Digite o dia de nascimento do recruta: ");
            scanf("%d",&dia);

            if (bissexto == 1 && mes==2){
                if (dia >= 1 && dia <= 29){
                    diaInvalido=0;
                }
            }else if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
                if (dia >=1 && dia<=31){
                    diaInvalido=0;
                }
            }else if (dia>=1 && dia <=30){
                    diaInvalido=0;
            }
        }
        novoRecruta->dataNascRecruta[0]=dia;
        novoRecruta->dataNascRecruta[1]=mes;
        novoRecruta->dataNascRecruta[2]=ano;

        valido=0;
        while(!valido){
            setbuf(stdin, NULL);
            printf("Informe o endereco do recruta: ");
            gets(novoRecruta->endereco);
            valido=isValido(novoRecruta->endereco,3);
        }

        novoRecruta->altura=-1;
        while(novoRecruta->altura<=0){
            printf("Informe a altura do recruta: ");
            scanf("%f",&novoRecruta->altura);
        }


        novoRecruta->peso=-1;
        while(novoRecruta->peso<=0){
            setbuf(stdin, NULL);
            printf("Informe o peso do recruta: ");
            scanf("%f",&novoRecruta->peso);
        }


        novoRecruta->quantIrmaos=-1;
        while(novoRecruta->quantIrmaos<0){
            setbuf(stdin, NULL);
            printf("Informe a quantidade de irm�os do recruta: ");
            scanf("%d",&novoRecruta->quantIrmaos);
        }


        valido=0;
        while(!valido){
            setbuf(stdin, NULL);
            printf("Informe o nome da progenitora do recruta: ");
            gets(novoRecruta->nomeProge);
            valido=isValido(novoRecruta->nomeProge,4);
        }

        novoRecruta->identProge = novoRecruta->identificacao;
        while(novoRecruta->identProge == novoRecruta->identificacao){
            printf("Informe a identificacao da progenitora do recruta: ");
            scanf("%d",&novoRecruta->identProge);
        }


        ano=0;
        mes=0;
        dia=0;
        diaInvalido=1;
        while (ano<=0){
            printf("Digite o ano de nascimento da progenitora do recruta: ");
            scanf("%d",&ano);
            if((novoRecruta->dataNascRecruta[2]-ano)<=0){
                printf("Ano invalido! A progenitora e' mais nova que o recruta!\n");
                ano=0;
            }
        }

        while (mes<1 || mes>12){
            printf("Digite o mes de nascimento da progenitora do recruta: ");
            scanf("%d",&mes);
        }

        if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ( ano % 400 == 0 ) ){
            bissexto= 1;
        }else{
            bissexto= 0;
        }

        while (diaInvalido == 1){
            printf("Digite o dia de nascimento da progenitora do recruta: ");
            scanf("%d",&dia);

            if (bissexto == 1 && mes==2){
                if (dia >= 1 && dia <= 29){
                    diaInvalido=0;
                }
            }else if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
                if (dia >=1 && dia<=31){
                    diaInvalido=0;
                }
            }else if (dia>=1 && dia <=30){
                    diaInvalido=0;
            }
        }
        novoRecruta->dataNascProge[0]=dia;
        novoRecruta->dataNascProge[1]=mes;
        novoRecruta->dataNascProge[2]=ano;

        /* Inicia o processo de inclus�o ordenada na lista de recrutas */
        /* Verifica se a lista se encontra vazia */
        if(lista->quant == 0){
            lista->itens[0] = *novoRecruta;
            lista->quant++;
            system("pause");
            return;
        }else{
            /* Encontra a posi��o adequada para inserir o recruta */
            for(i=0;i<lista->quant && !isEncontrado;i++){
                if(novoRecruta->identificacao==lista->itens[i].identificacao || novoRecruta->identificacao==lista->itens[i].identProge ){
                    printf("\nRecruta com a identificacao '%d' ja' se encontra na lista!\n",novoRecruta->identificacao);
                    system("pause");
                    return;
                }else if(novoRecruta->identificacao<lista->itens[i].identificacao){
                    printf("Encontrei a posicao!");
                    system("pause");
                    isEncontrado=1;
                }
            }
            
            if(isEncontrado){
                i--;
                /* Deslocando para posicao j+1 (da frente) o elemento j*/
                for(j=lista->quant-1;j>=i;j--){
                    lista->itens[j+1] = lista->itens[j];
                }
                lista->itens[i] = *novoRecruta;
                lista->quant++;
            }else{
                /* � o ultimo elemento da lista */
                lista->itens[i] = *novoRecruta;
                lista->quant++;
            }
        }
    }else{
        printf("\nA lista se econtra lotada!\n");
        system("pause");
        return;
    }

}

/* * * * * * * * *   EXCLUIR * * * * * * * * * * * * * * *  */

void excluiRecruta(struct sLista *lista){
    system("cls");
    int i, j, isEncontrado=0;
    int ident;

    printf("Digite a identificacao do recruta a ser excluido: ");
    scanf("%d",&ident);

    for(i=0; i<lista->quant && !isEncontrado; i++){
        if(lista->itens[i].identificacao==ident){
            isEncontrado++;
        }
    }
    i--;
    printf("VALOR DO I:%d\n\n",i);
    
    if(isEncontrado){
        for(j=i; j<lista->quant-1; j++){
            lista->itens[j] = lista->itens[j+1];
        }
        lista->quant--;
        printf("\nRecruta exterminado com sucesso!\n");
    }else{
        printf("\nIdentificacao '%d' de recruta nao encontrada na lista!\n", ident);
    }
    system("pause");
}

/* * * * * * * * *   ATUALIZAR  * * * * * * * * * * * * * * */

void atualizarRecruta(struct sLista *lista){
    int i,j, isEncontrado=0,codigo=-1;
    int ident;

    printf("Digite a identificacao do recruta a ser alterado: ");
    scanf("%d",&ident);

    for(i=0; i<lista->quant && !isEncontrado; i++){
        if(lista->itens[i].identificacao==ident){
            isEncontrado++;
        }
    }
    i--;
    printf("VALOR DO I:%d\n\n",i);
    if(isEncontrado){

        while(codigo<0 || codigo>9){
            printf("Identificacao do recruta: %d\n",lista->itens[i].identificacao);
            printf("1) Nome: %s\n",lista->itens[i].nome);
            printf("2) Data de nascimento do recruta: %d/%d/%d\n",lista->itens[i].dataNascRecruta[0],lista->itens[i].dataNascRecruta[1],lista->itens[i].dataNascRecruta[2]);
            printf("3) Endereco: %s\n",lista->itens[i].endereco);
            printf("4) Altura: %.2f\n",lista->itens[i].altura);
            printf("5) Peso: %.2f\n",lista->itens[i].peso);
            printf("6) Quantidade de irmaos: %d\n",lista->itens[i].quantIrmaos);
            printf("7) Nome da Progenitora: %s\n",lista->itens[i].nomeProge);
            printf("8) Identificacao da Progenitora: %d\n",lista->itens[i].identProge);
            printf("9) Data de nascimento da Progenitora: %d/%d/%d\n",lista->itens[i].dataNascProge[0],lista->itens[i].dataNascProge[1],lista->itens[i].dataNascProge[2]);

            printf("Digite o codigo do campo a ser alterado(0 para cancelar):");
            scanf("%d",&codigo);

            if (codigo!=0){
                int valido=0,bissexto=0;

                if(codigo==1){
                    valido=0;
                    while(!valido){
                        printf("Informe o novo nome do recruta: ");
                        gets(lista->itens[i].nome);
                        setbuf(stdin, NULL);
                        valido=isValido(lista->itens[i].nome,4);
                    }
                }


                if(codigo==2){

                    int ano=0,mes=0,dia=0;
                    int diaInvalido = 1;

                    while (ano<=0 || ano>1993){
                        printf("Digite o novo ano de nascimento do recruta: ");
                        scanf("%d",&ano);
                        if(ano>1993){
                            //Caso ele nao faca 18 anos no ano atual ou nao tenha feito 18 anos:
                            printf("Atencao: O recruta nao se encontra na idade de servico militar!\n");
                            ano=0;
                        }
                    }

                    while (mes<1 || mes>12){
                        printf("Digite o novo mes de nascimento do recruta: ");
                        scanf("%d",&mes);
                    }

                    if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ( ano % 400 == 0 ) ){
                        bissexto= 1;
                    }else{
                        bissexto= 0;
                    }

                    while (diaInvalido == 1){
                        printf("Digite o novo dia de nascimento do recruta:  ");
                        scanf("%d",&dia);

                        if (bissexto == 1 && mes==2){
                            if (dia >= 1 && dia <= 29){
                                diaInvalido=0;
                            }
                        }else if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
                            if (dia >=1 && dia<=31){
                                diaInvalido=0;
                            }
                        }else if (dia>=1 && dia <=30){
                                diaInvalido=0;
                        }
                    }
                    lista->itens[i].dataNascRecruta[0]=dia;
                    lista->itens[i].dataNascRecruta[1]=mes;
                    lista->itens[i].dataNascRecruta[2]=ano;
                }


                if(codigo==3){
                    valido=0;
                    while(!valido){
                        printf("Informe o novo endereco do recruta: ");
                        gets(lista->itens[i].endereco);
                        setbuf(stdin, NULL);
                        valido=isValido(lista->itens[i].endereco,3);
                    }
                }


                if(codigo==4){
                    lista->itens[i].altura=0;
                    while(lista->itens[i].altura<=0){
                        printf("Informe a nova altura do recruta: ");
                        scanf("%f",&lista->itens[i].altura);
                        setbuf(stdin, NULL);
                    }
                }


                if(codigo==5){
                    lista->itens[i].peso=0;
                    while(lista->itens[i].peso<=0){
                        printf("Informe o novo peso do recruta: ");
                        scanf("%f",&lista->itens[i].peso);
                        setbuf(stdin, NULL);
                    }
                }


                if(codigo==6){
                    lista->itens[i].quantIrmaos=-1;
                    while(lista->itens[i].quantIrmaos<0){
                        printf("Informe a nova quantidade de irmaos do recruta: ");
                        scanf("%d",&lista->itens[i].quantIrmaos);
                        setbuf(stdin, NULL);
                    }
                }


                if(codigo==7){
                    valido=0;
                    while(!valido){
                        printf("Informe o novo nome da progenitora do recruta: ");
                        gets(lista->itens[i].nomeProge);
                        setbuf(stdin, NULL);
                        valido=isValido(lista->itens[i].nomeProge,4);
                    }
                }


                if(codigo==8){
                    valido=0;
                    while(!valido || ident == lista->itens[i].identProge){
                        printf("Informe a nova identificacao da progenitora do recruta: ");
                        scanf("&d",&lista->itens[i].identProge);
                        setbuf(stdin, NULL);
                    }
                }


                if(codigo==9){

                    int ano=0,mes=0,dia=0;
                    int diaInvalido = 1;


                    while (ano<=0){
                        printf("Digite o novo ano de nascimento da progenitora do recruta: ");
                        scanf("%d",&ano);
                        if((lista->itens[i].dataNascRecruta[2]-ano)<=0){
                            printf("Ano invalido! A progenitora e' mais nova que o recruta!\n");
                            ano=0;
                        }
                    }

                    while (mes<1 || mes>12){
                        printf("Digite o novo mes de nascimento da progenitora do recruta: ");
                        scanf("%d",&mes);
                    }

                    if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ( ano % 400 == 0 ) ){
                        bissexto= 1;
                    }else{
                        bissexto= 0;
                    }

                    while (diaInvalido == 1){
                        printf("Digite o novo dia de nascimento da progenitora do recruta:  ");
                        scanf("%d",&dia);

                        if (bissexto == 1 && mes==2){
                            if (dia >= 1 && dia <= 29){
                                diaInvalido=0;
                            }
                        }else if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
                            if (dia >=1 && dia<=31){
                                diaInvalido=0;
                            }
                        }else if (dia>=1 && dia <=30){
                                diaInvalido=0;
                        }
                    }
                    lista->itens[i].dataNascProge[0]=dia;
                    lista->itens[i].dataNascProge[1]=mes;
                    lista->itens[i].dataNascProge[2]=ano;
                }

            }else{
                return;
            }
        }
    }else{
        printf("\nIdentificacao '%d' de recruta nao encontrada na lista!\n", ident);
    }
    system("pause");
}

/* * * * * * * * *   CONSULTAR  * * * * * * * * * * * * * * */

void consultarRecruta(struct sLista *lista){
    system("cls");
    int i,ident,isEncontrado=0;

    printf("Digite a identificacao do recruta a ser consultado: ");
    scanf("%d",&ident);

    for(i=0; i<lista->quant && !isEncontrado; i++){
        if(lista->itens[i].identificacao==ident){
            isEncontrado++;
        }
    }
    i--;
    printf("VALOR DO I:%d\n\n",i);
    if(isEncontrado){

        printf("Identificacao do recruta: %d\n",lista->itens[i].identificacao);
        printf(" Nome: %s\n",lista->itens[i].nome);
        printf(" Data de nascimento do recruta: %d/%d/%d\n",lista->itens[i].dataNascRecruta[0],lista->itens[i].dataNascRecruta[1],lista->itens[i].dataNascRecruta[2]);
        printf(" Endereco: %s\n",lista->itens[i].endereco);
        printf(" Altura: %.2f\n",lista->itens[i].altura);
        printf(" Peso: %.2f\n",lista->itens[i].peso);
        printf(" Quantidade de irmaos: %d\n",lista->itens[i].quantIrmaos);
        printf(" Nome da Progenitora: %s\n",lista->itens[i].nomeProge);
        printf(" Identificacao da Progenitora: %d\n",lista->itens[i].identProge);
        printf(" Data de nascimento da Progenitora: %d/%d/%d\n",lista->itens[i].dataNascProge[0],lista->itens[i].dataNascProge[1],lista->itens[i].dataNascProge[2]);
    }else{
        printf("\nIdentificacao '%d' de recruta nao encontrada na lista!\n", ident);
    }
    system("pause");
    return;
}

void listarTodos(struct sLista *lista){
    system("cls");
    int i;


    for(i=0; i<lista->quant; i++){
        printf("Identificacao do recruta: %d\n",lista->itens[i].identificacao);
        printf(" Nome: %s\n",lista->itens[i].nome);
        printf(" Data de nascimento do recruta: %d/%d/%d\n",lista->itens[i].dataNascRecruta[0],lista->itens[i].dataNascRecruta[1],lista->itens[i].dataNascRecruta[2]);
        printf(" Endereco: %s\n",lista->itens[i].endereco);
        printf(" Altura: %.2f\n",lista->itens[i].altura);
        printf(" Peso: %.2f\n",lista->itens[i].peso);
        printf(" Quantidade de irmaos: %d\n",lista->itens[i].quantIrmaos);
        printf(" Nome da Progenitora: %s\n",lista->itens[i].nomeProge);
        printf(" Identificacao da Progenitora: %d\n",lista->itens[i].identProge);
        printf(" Data de nascimento da Progenitora: %d/%d/%d\n",lista->itens[i].dataNascProge[0],lista->itens[i].dataNascProge[1],lista->itens[i].dataNascProge[2]);
        system("pause");
    }
    return;
}

void exibeExtremosAltura(struct sLista *lista){
    float menorAlt, maiorAlt;
    int menorAltInd=0,maiorAltInd=0,i;
    for(i=0; i<lista->quant; i++){
        if(i==0){
            menorAlt = lista->itens[i].altura;
            maiorAlt = lista->itens[i].altura;
        }
        if (lista->itens[i].altura<=menorAlt){
            menorAlt = lista->itens[i].altura;
            menorAltInd=i;
        }
        if (lista->itens[i].altura>=maiorAlt){
            maiorAlt = lista->itens[i].altura;
            maiorAltInd=i;
        }
    }
    
    printf("O recruta com a menor altura e' %s (ID %d) com %.2f m de altura\n",lista->itens[menorAltInd].nome,lista->itens[menorAltInd].identificacao,lista->itens[menorAltInd].altura);
    printf("O recruta com a maior altura e' %s (ID %d) com %.2f m de altura",lista->itens[maiorAltInd].nome,lista->itens[maiorAltInd].identificacao,lista->itens[maiorAltInd].altura);
    system("pause");
}

void exibeExtremosIdade(struct sLista *lista){
    int menorAno,maiorAno,menorInd,maiorInd;;
    int menorIdaInd=0,maiorIdaInd=0,i;
    for(i=0; i<lista->quant; i++){
        if(i==0){
            menorAno = lista->itens[i].dataNascRecruta[2];
            maiorAno=menorAno;
        }
        if (lista->itens[i].dataNascRecruta[2]<=menorAno){
            menorAno = lista->itens[i].dataNascRecruta[2];
            menorInd=i;
        }
        if (lista->itens[i].dataNascRecruta[2]>=maiorAno){
            maiorAno = lista->itens[i].dataNascRecruta[2];
            maiorInd=i;
        }
    }
    int menorMes,maiorMes;
    for(i=0;i<lista->quant;i++){
        if(i==0){
            menorMes = lista->itens[i].dataNascRecruta[1];
            maiorMes=menorMes;
        }
        if (lista->itens[i].dataNascRecruta[2] == menorAno && lista->itens[i].dataNascRecruta[1]<menorMes){
            menorMes = lista->itens[i].dataNascRecruta[1];
            menorInd=i;
        }
        if (lista->itens[i].dataNascRecruta[2] == maiorAno && lista->itens[i].dataNascRecruta[1]>maiorAno){
            maiorMes = lista->itens[i].dataNascRecruta[1];
            maiorInd=i;
        }
    }
    int menorDia,maiorDia;
    for(i=0;i<lista->quant;i++){
        if(i==0){
            menorMes = lista->itens[i].dataNascRecruta[0];
            maiorMes=menorMes;
        }
        if (lista->itens[i].dataNascRecruta[1] == menorMes && lista->itens[i].dataNascRecruta[2] == menorAno && lista->itens[i].dataNascRecruta[0]<menorDia){
            menorDia = lista->itens[i].dataNascRecruta[0];
            menorInd = i;
        }
        if (lista->itens[i].dataNascRecruta[1] == maiorMes && lista->itens[i].dataNascRecruta[2] == maiorAno && lista->itens[i].dataNascRecruta[0]>maiorDia){
            maiorDia = lista->itens[i].dataNascRecruta[0];
            maiorInd = i;
            
        }
    }
    printf("O recruta com a menor idade e' %s (ID %d).\n",lista->itens[maiorInd].nome,lista->itens[maiorInd].identificacao);
    printf("O recruta com a maior idade e' %s (ID %d).",lista->itens[menorInd].nome,lista->itens[menorInd].identificacao);
    system("pause");
}

int quantFilhosUnicos(struct sLista *lista){
    int quantFilhosUnicos=0,i;
    for(i=0; i<lista->quant; i++){
        if(lista->itens[i].quantIrmaos==0){
            quantFilhosUnicos++;
        }
    }
    return quantFilhosUnicos;
}

void exportaArquivo(struct sLista *lista){
    FILE *arq;
    char nomeArquivo[100];
    int i;
    setbuf(stdin, NULL);
    printf("\n\nDigite o nome do primeiro arquivo (de visualizacao) a ser criado: ");
    gets(nomeArquivo);
    arq = fopen(nomeArquivo, "w");
    
    for(i=0; i<lista->quant; i++){

        fprintf(arq, "%d\n",lista->itens[i].identificacao);
        fprintf(arq, "%s\n",lista->itens[i].nome);
        fprintf(arq, "%d\n",lista->itens[i].dataNascRecruta[0]);
        fprintf(arq, "%d\n",lista->itens[i].dataNascRecruta[1]);
        fprintf(arq, "%d\n",lista->itens[i].dataNascRecruta[2]);
        fprintf(arq, "%s\n",lista->itens[i].endereco);
        fprintf(arq, "%f\n",lista->itens[i].altura);
        fprintf(arq, "%f\n",lista->itens[i].peso);
        fprintf(arq, "%d\n",lista->itens[i].quantIrmaos);
        fprintf(arq, "%s\n",lista->itens[i].nomeProge);
        fprintf(arq, "%d\n",lista->itens[i].identProge);
        fprintf(arq, "%d\n",lista->itens[i].dataNascProge[0]);
        fprintf(arq, "%d\n",lista->itens[i].dataNascProge[1]);
        fprintf(arq, "%d\n",lista->itens[i].dataNascProge[2]);
    }
    fclose(arq);
    setbuf(stdin, NULL);
    printf("\n\nDigite o nome do segundo arquivo (de importacao) a ser criado: ");
    gets(nomeArquivo);
    arq = fopen(nomeArquivo, "w");
    
    for(i=0; i<lista->quant; i++){
        fprintf(arq, "%s %d %d %d %d %s %f %f %d %s %d %d %d %d\n",lista->itens[i].nome,lista->itens[i].identificacao,lista->itens[i].dataNascRecruta[0],lista->itens[i].dataNascRecruta[1],lista->itens[i].dataNascRecruta[2],lista->itens[i].endereco,lista->itens[i].altura,lista->itens[i].peso,lista->itens[i].quantIrmaos,lista->itens[i].nomeProge,lista->itens[i].identProge,lista->itens[i].dataNascProge[0],lista->itens[i].dataNascProge[1],lista->itens[i].dataNascProge[2]);
    }
    fclose(arq);
    system("pause");
}
int menu();
void verificaOpcao(int,struct sLista *);


int main(){
    struct sLista lista;
    lista.quant = 0;
    int quantAlist=-1;
    char resp = 'a';
    
    setbuf(stdin, NULL);
    printf("Deseja importar recrutas de um arquivo?(<s> para sim, qualquer outra coisa para nao):");
    scanf("%c",&resp);
    if(resp!='s' && resp!='S'){
        while(quantAlist<=0){
            printf("Digite a quantidade de recrutas a serem alistados:");
            scanf("%d",&quantAlist);
        }
        lista.itens = (struct sRecruta*)malloc(sizeof(struct sRecruta)*quantAlist);
        lista.valorMax=quantAlist;
    }else{
        //Na primeira linha vai o contingente
        /*
            char nome[100];
           //Identifica��o: CPF?
           unsigned long int identificacao;
           int dataNascRecruta[3];
           char endereco[250];
           float altura,peso;
           int quantIrmaos;
           char nomeProge[100];
           unsigned long int identProge;
           int dataNascProge[3];
        */
        FILE *arq;
        char nomeArquivo[100];
        int valorMax;
        
        printf("\nInfome o nome do arquivo de importacao: ");
        gets(nomeArquivo);
        
        arq = fopen(nomeArquivo, "r");
        fscanf(arq, "%d", &valorMax);
        
        lista.itens = (struct sRecruta*)malloc(sizeof(struct sRecruta)*quantAlist);
        lista.valorMax=quantAlist;
        
        while(!feof(arq))  
        {
            //fscanf(arq, "%s%d%d%d%d%s%f%f%d%s%d%d%d%d",&lista->itens[i].nome,&lista->itens[i].identificacao,&lista->itens[i].dataNascRecruta[0],&lista->itens[i].dataNascRecruta[1],&lista->itens[i].dataNascRecruta[2],&lista->itens[i].endereco,&lista->itens[i].altura,lista->itens[i].peso,lista->itens[i].quantIrmaos,lista->itens[i].nomeProge,lista->itens[i].identProge,lista->itens[i].dataNascProge[0],lista->itens[i].dataNascProge[1],lista->itens[i].dataNascProge[2]);
        
        }
        fclose(arq);
        printf("Importacao realizada com sucesso!
    }
    int opcao;
    resp='a';
    do{
        opcao=-1;
        while(opcao!=0){
            system("cls");
            opcao = menu();
            verificaOpcao(opcao,&lista);
        }        
        setbuf(stdin, NULL);

        printf("Deseja realmente sair?  (<s> para sim, qualquer outra coisa para nao)");

        scanf("%c",&resp);
    }while(resp !='s' && resp != 'S');

    system ("pause");
    return 0;
}

int menu(){
    int opcao;
    do{
        setbuf(stdin, NULL);
        printf("Escolha uma opcao:\n  1. Alistar Recruta.\n  2. Excluir Recruta.\n  3. Atualizar recruta.\n  4. Consultar recruta.\n  5. Exibir o recruta mais alto e mais baixo.\n  6. Exibir o recruta mais novo e mais velho.\n  7. Exibir quantidades de filhos unicos cadastrados.\n  8. Exportar arquivo.\n  0. Sair\n\n  Opcao:");
        scanf("%d",&opcao);
    }while(opcao <0 || opcao >9);

    return opcao;
}

void verificaOpcao(int opcao, struct sLista *lista){
    int sair=0;
    if(opcao==1){
        alistarRecruta(lista);
    }else if(opcao==2){
        excluiRecruta(lista);
    }else if(opcao==3){
        atualizarRecruta(lista);
    }else if(opcao==4){
        consultarRecruta(lista);
    }else if(opcao==5){
        exibeExtremosAltura(lista);
    }else if(opcao==6){
        exibeExtremosIdade(lista);
    }else if(opcao==7){
        printf("\nExistem %d filhos unicos alistados!",quantFilhosUnicos(lista));
        system("pause");
    }else if(opcao==8){
        exportaArquivo(lista);
    }else if(opcao==9){
        listarTodos(lista);
    }
    return;
}

int isValido(char *string,int tipo){
    /*  Tipo 1: Alfanumerico
        Tipo 2: Alfa
        Tipo 3: Alfanumerico + ponto ( endere�o )
        Tipo 4: Alfanumerico + espaco (nome)*/

        int i;
        if(tipo==1){
            for(i=0;string[i]!=0;i++){
                //48=0,57=9;   65=A, 90=Z ;97=a, 122=z ;
                if((string[i]<48) || (string[i]> 57 && string[i]<65) || (string[i]>90 && string[i]<97) || (string[i]>122)){
                    //DEBUG: printf("char[i]:%c,%d",string[i],string[i]);
                    return 0;
                }
            }
        }
        if(tipo==2){
            for(i=0;string[i]!=0;i++){
                if((string[i]<65) || (string[i]>90 && string[i]<97) || string[i]>122){
                    //DEBUG: printf("char[i]:%c,%d",string[i],string[i]);
                    return 0;
                }
            }
        }
        if(tipo==3){
            for(i=0;string[i]!=0;i++){
                //48=0,57=9;   65=A, 90=Z ;97=a, 122=z ;
                //Permite '.' ',' e  ' ' alem dos carac. alfanumericos
                if((string[i]!=46 && string[i]!= 44 && string[i]!=32) && (string[i]<48 || (string[i]> 57 && string[i]<65) || (string[i]>90 && string[i]<97) || string[i]>122)){
                    //DEBUG: printf("char[i]:%c,%d",string[i],string[i]);
                    return 0;
                }
            }
        }
        if(tipo==4){
            for(i=0;string[i]!=0;i++){
                //48=0,57=9;   65=A, 90=Z ;97=a, 122=z ;
                if((string[i]!=32)&&((string[i]<65) || (string[i]>90 && string[i]<97) || string[i]>122)){
                    //DEBUG: printf("char[i]:%c,%d",string[i],string[i]);
                    return 0;
                }
            }
        }
        return 1;

}
/*
1 � O Ex�rcito Brasileiro (EB) pretende fazer um Cadastro Nacional de Recrutas ao
Ex�rcito (CaNaREx) o qual manter� um cadastro de 500 recrutas, n�mero m�ximo do
contingente, do pr�ximo ano. O CaNaREx deve ser implementado atrav�s de uma lista,
onde ser�o armazenados todos os dados dos alistados para o servi�o militar obrigat�rio.
Os dados a serem obtidos do jovem alistado s�o os seguintes: Nome, Identifica��o, Data
de Nascimento, Endere�o Residencial, Altura em metros, Peso em quilogramas,
Quantidade de Irm�os, Nome da progenitora, Identifica��o da progenitora e Data de
Nascimento da progenitora.
Como o EB � �p� no ch�o�, a lista de recrutas deve ser ordenada pela Identifica��o do
Recruta. O CaNaREx deve contar com a seguintes fun��es:

� Alistar Recruta, que deve ser pedir todos os dados do Recruta e averiguar se ele
est� realmente da idade do servi�o militar obrigat�rio;

� Excluir Recruta, dado o n�mero de identifica��o do recruta, ele ser�
exterminado da lista;

� Atualizar Recruta, dado o n�mero de identifica��o do recruta, seus dados ser�o
apresentados em tela e a op��o de atualizar campo a campo ser� dada ao
operador do sistema; e

� Consultar Recruta, dado o n�mero de identifica��o do recruto, buscar� seus
dados e os apresentar� na tela.

Al�m disso, o EB pediu duas fun��es secretas, uma que retorna o recruta mais alto e o
mais baixo alistado e outra que retorna o mais velho e o mais novo recruta alistado.
*/

