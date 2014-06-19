#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio  01 - Lista de Exercícios 10                  */
/* CC2621 --2011    --turma 610   
/***************************  FEI  *************************/


#define TAM 5



struct sRecruta
{
       char nome[100];
       //Identificação: CPF?
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
       struct sRecruta itens[TAM];
       int quant;
};

int isValido(char*,int);

/* * * * * * * * * * ALISTAR * * * * * * * * * * * * * * *  */
void alistarRecruta(struct sLista *lista){
    system("cls");
    int isEncontrado=0, i=0, j=0,valido;
    struct sRecruta *novoRecruta;

    /* Se não estiver cheia */
    if(lista->quant < TAM){

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
            printf("Digite o dia de nascimento do recruta:  ");
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
            printf("Informe a quantidade de irmãos do recruta: ");
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
            printf("Digite o dia de nascimento da progenitora do recruta:  ");
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

        /* Inicia o processo de inclusão ordenada na lista de recrutas */
        /* Verifica se a lista se encontra vazia */
        if(lista->quant == 0){
            lista->itens[0] = *novoRecruta;
            lista->quant++;
            printf("E o primeiro!");
            system("pause");
            return;
        }else{
            /* Encontra a posição adequada para inserir o recruta */
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
                /* Deslocando para posicao j+1 (da frente) o elemento j*/
                for(j=lista->quant-1;j>=i;j--){
                    lista->itens[j+1] = lista->itens[j];
                }
                lista->itens[i] = *novoRecruta;
                lista->quant++;
            }else{
                printf("E ultimo!");
                /* É o ultimo elemento da lista */
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
    int i, j, isEncontrado;
    unsigned long int  ident;

    printf("Digite a identificacao do recruta a ser excluido: ");
    scanf("%d",&ident);

    for(i=0; i<lista->quant && !isEncontrado; i++){
        if(lista->itens[i].identificacao==ident){
            isEncontrado++;
        }
    }

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
    int i,j, isEncontrado,codigo=-1;
    unsigned long int ident[100];

    printf("Digite a identificacao do recruta a ser alterado: ");
    scanf("%d",&ident);

    for(i=0; i<lista->quant && !isEncontrado; i++){
        if(strcmp(lista->itens[i].identificacao,ident)==0){
            isEncontrado++;
        }
    }

    if(isEncontrado){

        while(codigo<0 || codigo>9){
            printf("Identificacao do recruta: %d\n",lista->itens[i].identificacao);
            printf("1) Nome: %s\n",lista->itens[i].nome);
            printf("2) Data de nascimento do recruta: %d/%d/%d\n",lista->itens[i].dataNascRecruta[0],lista->itens[i].dataNascRecruta[1],lista->itens[i].dataNascRecruta[2]);
            printf("3) Endereco: %s\n",lista->itens[i].endereco);
            printf("4) Altura: %.2f\n",lista->itens[i].altura);
            printf("5) Peso: %.2f\n",lista->itens[i].peso);
            printf("6) Quantidade de irmaos: %d\n",lista->itens[i].quantIrmaos);
            printf("7) Nome da Progenitora: %s",lista->itens[i].nomeProge);
            printf("8) Identificacao da Progenitora: %d",lista->itens[i].identProge);
            printf("9) Data de nascimento da Progenitora: %d/%d/%d",lista->itens[i].dataNascProge[0],lista->itens[i].dataNascProge[1],lista->itens[i].dataNascProge[2]);

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

                    while (ano<=0){
                        printf("Digite o novo ano de nascimento do recruta: ");
                        scanf("%d",&ano);
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
        printf("\nIdentificacao '%s' de recruta nao encontrada na lista!\n", ident);
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
        if(strcmp(lista->itens[i].identificacao,ident)==0){
            isEncontrado++;
        }
    }

    if(isEncontrado){

        printf("Identificacao do recruta: %d\n",lista->itens[i].identificacao);
        printf(" Nome: %s\n",lista->itens[i].nome);
        printf(" Data de nascimento do recruta: %d/%d/%d\n",lista->itens[i].dataNascRecruta[0],lista->itens[i].dataNascRecruta[1],lista->itens[i].dataNascRecruta[2]);
        printf(" Endereco: %s\n",lista->itens[i].endereco);
        printf(" Altura: %.2f\n",lista->itens[i].altura);
        printf(" Peso: %.2f\n",lista->itens[i].peso);
        printf(" Quantidade de irmaos: %d\n",lista->itens[i].quantIrmaos);
        printf(" Nome da Progenitora: %s",lista->itens[i].nomeProge);
        printf(" Identificacao da Progenitora: %d",lista->itens[i].identProge);
        printf(" Data de nascimento da Progenitora: %d/%d/%d",lista->itens[i].dataNascProge[0],lista->itens[i].dataNascProge[1],lista->itens[i].dataNascProge[2]);
    }else{
        printf("\nIdentificacao '%s' de recruta nao encontrada na lista!\n", ident);
    }
    system("pause");
    return;
}


void exibeExtremosAltura(struct sLista *);
void exibeExtremosIdade(struct sLista *);
int menu();
void verificaOpcao(int,struct sLista *);


int main(){
    struct sLista lista;
    lista.quant = 0;
    int opcao=-1;
    char resp = 'a';
    do{

        while(opcao!=0){
            system("cls");
            opcao = menu();
            verificaOpcao(opcao,&lista);
            printf("NOME: %s\nNOME: %s",lista.itens[0].nome,lista.itens[1].nome);
        }

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
        printf("Escolha uma opcao:\n  1. Alistar Recruta.\n  2. Excluir Recruta.\n  3. Atualizar recruta.\n  4. Consultar recruta.\n  0. Sair\n\n  Opcao:");
        scanf("%d",&opcao);
    }while(opcao <0 || opcao >6);

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
        //exibeExtremosAltura(lista);
    }else if(opcao==6){
        //exibeExtremosIdade(lista);
    }
    return;
}

int isValido(char *string,int tipo){
    /*  Tipo 1: Alfanumerico
        Tipo 2: Alfa
        Tipo 3: Alfanumerico + ponto ( endereço )
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
1 – O Exército Brasileiro (EB) pretende fazer um Cadastro Nacional de Recrutas ao
Exército (CaNaREx) o qual manterá um cadastro de 500 recrutas, número máximo do
contingente, do próximo ano. O CaNaREx deve ser implementado através de uma lista,
onde serão armazenados todos os dados dos alistados para o serviço militar obrigatório.
Os dados a serem obtidos do jovem alistado são os seguintes: Nome, Identificação, Data
de Nascimento, Endereço Residencial, Altura em metros, Peso em quilogramas,
Quantidade de Irmãos, Nome da progenitora, Identificação da progenitora e Data de
Nascimento da progenitora.
Como o EB é “pé no chão”, a lista de recrutas deve ser ordenada pela Identificação do
Recruta. O CaNaREx deve contar com a seguintes funções:

• Alistar Recruta, que deve ser pedir todos os dados do Recruta e averiguar se ele
está realmente da idade do serviço militar obrigatório;

• Excluir Recruta, dado o número de identificação do recruta, ele será
exterminado da lista;

• Atualizar Recruta, dado o número de identificação do recruta, seus dados serão
apresentados em tela e a opção de atualizar campo a campo será dada ao
operador do sistema; e

• Consultar Recruta, dado o número de identificação do recruto, buscará seus
dados e os apresentará na tela.

Além disso, o EB pediu duas funções secretas, uma que retorna o recruta mais alto e o
mais baixo alistado e outra que retorna o mais velho e o mais novo recruta alistado.
*/

