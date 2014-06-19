#include <stdio.h>

#define TAM 5

struct sRecruta
{
       char nome[100];
       char identificacao[100];
       int dataNascRecruta[3];
       char endereco[250];
       float altura,peso;
       int quantIrmaos;
       char nomeProge[100];
       char identProge[100];
       int dataNascProge[3];
       
       
};


struct sLista
{
       struct sRecruta itens[TAM];
       int quant;
};

void alistarRecruta(struct sLista *lista){
    struct sRecruta *novoRecruta;
    int isEscontrado=0, i=0, j=0;
    /* Se não estiver cheia */
    if(lista->quant < TAM){
        
        novoRecruta = (struct sRecruta*) malloc(sizeof(struct sRecruta));
        
        //TODO: ISALPHA
        printf("Informe o nome do recruta: ");
        gets(novoRecruta->nome);
        setbuf(stdin, NULL);
        
        printf("Informe a identificacao do recruta: ");
        gets(novoRecruta->identificacao);
        setbuf(stdin, NULL);
        
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
        novoRecruta->dataNasc[1]=dia;
        novoRecruta->dataNasc[2]=mes;
        novoRecruta->dataNasc[3]=ano;

        
        printf("Informe o endereco do recruta: ");
        gets(novoRecruta->endereco);
        setbuf(stdin, NULL);
        
        printf("Informe a altura do recruta: ");
        scanf("%f",&novoRecruta->altura);
        setbuf(stdin, NULL);
        
        printf("Informe o peso do recruta: ");
        scanf("%f",&novoRecruta->peso);
        setbuf(stdin, NULL);
        
        printf("Informe a quantidade de irmãos do recruta: ");
        scanf("%d",&novoRecruta->quantIrmaos);
        setbuf(stdin, NULL);
        
        printf("Informe o nome da progenitora do recruta: ");
        gets(novoRecruta->nomeProge);
        setbuf(stdin, NULL);
        
        printf("Informe a identificacao da progenitora do recruta: ");
        gets(novoRecruta->identProge);
        setbuf(stdin, NULL);
        
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
        }else{
            
            /* Encontra a posição correta para inserir o recruta */
            for(i=0;i<lista->quant && !isEncontrado;i++){
                if(lista->itens[i].identificacao >= novo->identificacao){
                    if(lista->itens[i].numero == novo->numero){
                        printf("\nAluno numero: %d jah existe na lista!\n");
                        system("pause");
                        return;
                    }else{
                        achei=1;
                    }
                }else{
                    i++;
                }
            }
            if(achei) // achei a posicao (i) para inserir o elemento no meio da lista
            {
                /* Deslocando para posicao j+1 (da frente) o elemento j*/
                for(j=lista->quantidade-1; j>=i; j--)
                {
                    lista->itens[j+1] = lista->itens[j];
                }
                lista->itens[i] = *novo;
                lista->quantidade++;
            }
            else /* nao achou ninguem maior ou igual*/
            {
                /*eh o maior elemento da lista, insere no final*/
                lista->itens[i] = *novo;
                lista->quantidade++;
            }
        }
    }
    else
    {
        printf("\nA lista esta cheia!\n");
        system("pause");
    }
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
