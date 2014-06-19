#include <stdio.h>
#include <stdlib.h>
#include <Hora.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//*                        */
/* Exercicio  01 - Lista de Exercícios 10                  */
/* CC3651 --2012    --turma 610                            */
/***********************************************************/


#define TAM 200
//ATENCAO: Para acessar a função secreta, basta digitar 5 ou 6 no menu.

struct stProduto
{
    char codigo[100];
    char descricao[256];
    double quant;
    
};
struct stVenda
{
    struct stHora hora;
    char cpf[15];
    struct stProduto *produtos
    double quant;
    int hora,minuto,segundo; 
};

struct stLista
{
       struct stVenda vendas[TAM];
       int quant;
};

int isAnterior(struct sRecruta *,struct sRecruta);
void alistarRecruta(struct sLista *);
void excluiRecruta(struct sLista*);
void atualizarRecruta(struct sLista *);
void consultarRecruta(struct sLista *);
void exibeExtremosAltura(struct sLista *);
void exibeExtremosIdade(struct sLista *);
int menu();
void verificaOpcao(int,struct sLista *);
int isValido(char*,int);

int main(){
    struct sLista lista;
    lista.quant = 0;
    int opcao=-1;
    char resp = 'a';
    do{
        while(opcao!=0){
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
        //consultarRecruta(lista);
    }else if(opcao==5){
        //exibeExtremosAltura(lista);
    }else if(opcao==6){
        //exibeExtremosIdade(lista);
    }
    return;
}
void alistarRecruta(struct sLista *lista){
    struct sRecruta *novoRecruta;
    int isEncontrado=0, i=0, j=0;
    int valido;

    /* Se não estiver cheia */
    if(lista->quant < TAM){
        novoRecruta = (struct sRecruta*) malloc(sizeof(struct sRecruta));
        setbuf(stdin, NULL);
        valido=0;
        while(!valido){
            printf("Informe o nome do recruta: ");
            gets(novoRecruta->nome);
            setbuf(stdin, NULL);
            valido=isValido(novoRecruta->nome,4);
        }
        setbuf(stdin, NULL);
        valido=0;
        while(!valido){
            printf("Informe a identificacao do recruta: ");
            gets(novoRecruta->identificacao);
            setbuf(stdin, NULL);
            valido=isValido(novoRecruta->identificacao,1);
        }

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
        novoRecruta->dataNascRecruta[1]=dia;
        novoRecruta->dataNascRecruta[2]=mes;
        novoRecruta->dataNascRecruta[3]=ano;
        setbuf(stdin, NULL);
        valido=0;
        while(!valido){
            printf("Informe o endereco do recruta: ");
            gets(novoRecruta->endereco);
            setbuf(stdin, NULL);
            valido=isValido(novoRecruta->endereco,3);
        }
        setbuf(stdin, NULL);
        novoRecruta->altura=-1;
        while(novoRecruta->altura<=0){
            printf("Informe a altura do recruta: ");
            scanf("%f",&novoRecruta->altura);
            setbuf(stdin, NULL);
        }
        setbuf(stdin, NULL);
        novoRecruta->peso=-1;
        while(novoRecruta->peso<=0){
            printf("Informe o peso do recruta: ");
            scanf("%f",&novoRecruta->peso);
            setbuf(stdin, NULL);
        }
        setbuf(stdin, NULL);
        novoRecruta->quantIrmaos=-1;
        while(novoRecruta->quantIrmaos<0){
            printf("Informe a quantidade de irmãos do recruta: ");
            scanf("%d",&novoRecruta->quantIrmaos);
            setbuf(stdin, NULL);
        }
        setbuf(stdin, NULL);
        valido=0;
        while(!valido){
            printf("Informe o nome da progenitora do recruta: ");
            gets(novoRecruta->nomeProge);
            setbuf(stdin, NULL);
            valido=isValido(novoRecruta->nomeProge,4);
        }
        setbuf(stdin, NULL);
        valido=0;
        while(!valido){
            printf("Informe a identificacao da progenitora do recruta: ");
            gets(novoRecruta->identProge);
            setbuf(stdin, NULL);
            valido=isValido(novoRecruta->identProge,1);
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
        novoRecruta->dataNascProge[1]=dia;
        novoRecruta->dataNascProge[2]=mes;
        novoRecruta->dataNascProge[3]=ano;
        /* Inicia o processo de inclusão ordenada na lista de recrutas */
        /* Verifica se a lista se encontra vazia */
        if(lista->quant == 0){
            lista->itens[0] = *novoRecruta;
            lista->quant++;
            free(novoRecruta);
            return;
        }else{
            /* Encontra a posição adequada para inserir o recruta */
            for(i=0;i<lista->quant && !isEncontrado;i++){
                if(isAnterior(novoRecruta,lista->itens[i])==-1){
                    printf("\nRecruta com a identificacao '%s' ja' se encontra na lista!\n",novoRecruta->identificacao);
                    system("pause");
                    free(novoRecruta);
                    return;
                }else if(isAnterior(novoRecruta,lista->itens[i])==1){
                    isEncontrado=1;
                }
            }if(isEncontrado){
                /* Deslocando para posicao j+1 (da frente) o elemento j*/
                for(j=lista->quant-1;j>=i;j--){
                    lista->itens[j+1] = lista->itens[j];
                }
                lista->itens[i] = *novoRecruta;
                lista->quant++;
            }else{
                /* É o ultimo elemento da lista */
                lista->itens[i] = *novoRecruta;
                lista->quant++;
            }
        }
    }else{
        printf("\nA lista se econtra lotada!\n");
        system("pause");
    }

}

int isAnterior(struct sRecruta *recruta1,struct sRecruta recruta2){
    int isIgual=0,cont=0;
    /* Verifica se os caracteres são de tipos diferentes (um é alpha e o outro é numerico ou vice versa) */
    do{
        if(recruta1->identificacao[cont] != recruta2.identificacao[cont]){
            isIgual=0;
            //48=0,57=9;   65=A, 90=Z ;

            if(recruta1->identificacao[cont] < recruta2.identificacao[cont]){
                //o primeiro e' anterior ao segunto
                return 1;
            }else{
                //o segunto é anterior ao primeiro
                return 0;
            }
        }else if(recruta1->identificacao[cont]==0){
            //Os dois são iguais
            return -1;
        }else{
            isIgual=1;
            cont++;
        }
    }while(isIgual);
}

void excluiRecruta(struct sLista *lista){
    int i, j, isEncontrado;
    char ident[100];

    printf("Digite a identificacao do recruta a ser excluido: ");
    gets(ident);

    for(i=0; i<lista->quant && !isEncontrado; i++){
        if(strcmp(lista->itens[i].identificacao,ident)==0){
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
        printf("\nIdentificacao '%s' de recruta nao encontrada na lista!\n", ident);
    }
    system("pause");
}

void atualizarRecruta(struct sLista *lista){
    int i,j, isEncontrado;
    char ident[100];

    setbuf(stdin, NULL);
    printf("Digite a identificacao do recruta a ser alterado: ");
    gets(ident);

    for(i=0; i<lista->quant && !isEncontrado; i++){
        if(strcmp(lista->itens[i].identificacao,ident)==0){
            isEncontrado++;
        }
    }

    if(isEncontrado){
        int alteraIdent=0,valido=0,bissexto=0;
        struct sRecruta *novoRecruta;
        novoRecruta = (struct sRecruta*) malloc(sizeof(struct sRecruta));
        char resp='a';
        setbuf(stdin, NULL);
        printf("Deseja alterar o nome do recruta?  (<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){
            valido=0;
            while(!valido){
                printf("Informe o novo nome do recruta: ");
                gets(novoRecruta->nome);
                setbuf(stdin, NULL);
                valido=isValido(novoRecruta->nome,4);
            }
        }else{
            strcpy(novoRecruta->nome, lista->itens[i].nome);
        }

        setbuf(stdin, NULL);
        printf("Deseja alterar a data de nascimento do recruta?(<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){
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
            novoRecruta->dataNascRecruta[1]=dia;
            novoRecruta->dataNascRecruta[2]=mes;
            novoRecruta->dataNascRecruta[3]=ano;
        }else{
            novoRecruta->dataNascRecruta[1]= lista->itens[i].dataNascRecruta[1];
            novoRecruta->dataNascRecruta[2]= lista->itens[i].dataNascRecruta[2];
            novoRecruta->dataNascRecruta[3]= lista->itens[i].dataNascRecruta[3];
        }

        setbuf(stdin, NULL);
        printf("Deseja alterar o endereco do recruta?(<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){
            valido=0;
            while(!valido){
                printf("Informe o novo endereco do recruta: ");
                gets(novoRecruta->endereco);
                setbuf(stdin, NULL);
                valido=isValido(novoRecruta->endereco,3);
            }
        }else{
            strcpy(novoRecruta->endereco, lista->itens[i].endereco);
        }

        setbuf(stdin, NULL);
        printf("Deseja alterar a altura do recruta?(<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){
            novoRecruta->altura=-1;
            while(novoRecruta->altura<=0){
                printf("Informe a nova altura do recruta: ");
                scanf("%f",&novoRecruta->altura);
                setbuf(stdin, NULL);
            }
        }else{
            novoRecruta->altura=lista->itens[i].altura;
        }

        setbuf(stdin, NULL);
        printf("Deseja alterar o peso do recruta?(<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){
            novoRecruta->peso=-1;
            while(novoRecruta->peso<=0){
                printf("Informe o novo peso do recruta: ");
                scanf("%f",&novoRecruta->peso);
                setbuf(stdin, NULL);
            }
        }else{
            novoRecruta->peso=lista->itens[i].peso;
        }

        setbuf(stdin, NULL);
        printf("Deseja alterar a quantidade de irmaos do recruta?(<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){
            novoRecruta->quantIrmaos=-1;
            while(novoRecruta->quantIrmaos<0){
                printf("Informe a nova quantidade de irmaos do recruta: ");
                scanf("%d",&novoRecruta->quantIrmaos);
                setbuf(stdin, NULL);
            }
        }else{
            novoRecruta->quantIrmaos=lista->itens[i].quantIrmaos;
        }

        setbuf(stdin, NULL);
        printf("Deseja alterar o nome da progenitora do recruta?(<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){
            valido=0;
            while(!valido){
                printf("Informe o novo nome da progenitora do recruta: ");
                gets(novoRecruta->nomeProge);
                setbuf(stdin, NULL);
                valido=isValido(novoRecruta->nomeProge,4);
            }
        }else{
            strcpy(novoRecruta->nomeProge, lista->itens[i].nomeProge);
        }

        setbuf(stdin, NULL);
        printf("Deseja alterar a identificacao da progenitora do recruta?(<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){
            valido=0;
            while(!valido){
                printf("Informe a nova identificacao da progenitora do recruta: ");
                gets(novoRecruta->identProge);
                setbuf(stdin, NULL);
                valido=isValido(novoRecruta->identProge,1);
            }
        }else{
            strcpy(novoRecruta->identProge, lista->itens[i].identProge);
        }



        setbuf(stdin, NULL);
        printf("Deseja alterar a data de nascimento da progenitora do recruta?(<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        setbuf(stdin, NULL);
        if(resp=='s' || resp=='S'){

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
            novoRecruta->dataNascProge[1]=dia;
            novoRecruta->dataNascProge[2]=mes;
            novoRecruta->dataNascProge[3]=ano;
        }else{
            novoRecruta->dataNascProge[1]= lista->itens[i].dataNascProge[1];
            novoRecruta->dataNascProge[2]= lista->itens[i].dataNascProge[2];
            novoRecruta->dataNascProge[3]= lista->itens[i].dataNascProge[3];
        }

        setbuf(stdin, NULL);
        printf("Deseja alterar a identificacao do recruta?  (<s> para sim, qualquer outra coisa para nao)");
        scanf("%c",&resp);
        if(resp=='s' || resp=='S'){
            alteraIdent=1;
            valido=0;
            while(!valido){
                printf("Informe a nova identificacao do recruta: ");
                gets(novoRecruta->identificacao);
                setbuf(stdin, NULL);
                valido=isValido(novoRecruta->identificacao,1);
                if(valido){
                    for(i=0;i<lista->quant && !isEncontrado;i++){
                        if(isAnterior(novoRecruta,lista->itens[i])==-1){
                            printf("\nRecruta com a identificacao '%s' ja' se encontra na lista!\n",novoRecruta->identificacao);
                            system("pause");
                            valido=0;
                        }
                    }
                }
            }
        }
        if(alteraIdent=1){
            /* Primeiro exclui o  recruta anterior, depois adiciona o recruta alterado em sua posicao correta */
            strcpy(ident, lista->itens[i].identificacao);

            for(i=0; i<lista->quant && !isEncontrado; i++){
                if(strcmp(lista->itens[i].identificacao,ident)==0){
                    isEncontrado++;
                }

            }

            for(j=i; j<lista->quant-1; j++){
                lista->itens[j] = lista->itens[j+1];
            }
            lista->quant--;
            if(lista->quant == 0){
                lista->itens[0] = *novoRecruta;
                lista->quant++;
            }else{

                /* Encontra a posição adequada para inserir o recruta */
                for(i=0;i<lista->quant && !isEncontrado;i++){
                    if(isAnterior(novoRecruta,lista->itens[i])==1){
                        isEncontrado=1;
                    }

                }if(isEncontrado){
                    /* Deslocando para posicao j+1 o elemento j*/
                    for(j=lista->quant-1;j>=i;j--){
                        lista->itens[j+1] = lista->itens[j];
                    }
                    lista->itens[i] = *novoRecruta;
                    lista->quant++;
                }else{
                    /* É o ultimo elemento da lista */
                    lista->itens[i] = *novoRecruta;
                    lista->quant++;
                }
            }
        }else{
            strcpy(lista->itens[i].nome, novoRecruta->nome);
            lista->itens[i].dataNascRecruta[1] = novoRecruta->dataNascRecruta[1];
            lista->itens[i].dataNascRecruta[2] = novoRecruta->dataNascRecruta[2];
            lista->itens[i].dataNascRecruta[3] = novoRecruta->dataNascRecruta[3];
            strcpy(lista->itens[i].endereco, novoRecruta->endereco);
            lista->itens[i].altura = novoRecruta->altura;
            lista->itens[i].peso = novoRecruta->peso;
            lista->itens[i].quantIrmaos = novoRecruta->quantIrmaos;
            strcpy(lista->itens[i].nomeProge, novoRecruta->nomeProge);
            strcpy(lista->itens[i].identProge, novoRecruta->identProge);
            lista->itens[i].dataNascProge[1] = novoRecruta->dataNascProge[1];
            lista->itens[i].dataNascProge[2] = novoRecruta->dataNascProge[2];
            lista->itens[i].dataNascProge[3] = novoRecruta->dataNascProge[3];
        }
        printf("\nRecruta alterado com sucesso!\n");
    }else{
        printf("\nIdentificacao '%s' de recruta nao encontrada na lista!\n", ident);
    }
    system("pause");
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
                    printf("char[i]:%c,%d",string[i],string[i]);
                    return 0;
                }
            }
        }
        if(tipo==2){
            for(i=0;string[i]!=0;i++){
                if((string[i]<65) || (string[i]>90 && string[i]<97) || string[i]>122){
                    printf("char[i]:%c,%d",string[i],string[i]);
                    return 0;
                }
            }
        }
        if(tipo==3){
            for(i=0;string[i]!=0;i++){
                //48=0,57=9;   65=A, 90=Z ;97=a, 122=z ;
                //Permite '.' ',' e  ' ' alem dos carac. alfanumericos
                if((string[i]!=46 && string[i]!= 44 && string[i]!=32) && (string[i]<48 || (string[i]> 57 && string[i]<65) || (string[i]>90 && string[i]<97) || string[i]>122)){
                    printf("char[i]:%c,%d",string[i],string[i]);
                    return 0;
                }
            }
        }
        if(tipo==4){
            for(i=0;string[i]!=0;i++){
                //48=0,57=9;   65=A, 90=Z ;97=a, 122=z ;
                if((string[i]!=32)&&((string[i]<65) || (string[i]>90 && string[i]<97) || string[i]>122)){
                    printf("char[i]:%c,%d",string[i],string[i]);
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
