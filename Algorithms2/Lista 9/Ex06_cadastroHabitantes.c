#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Tamanho do vetor da struct */
#define TAMANHO 500

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  06 - Lista de Exercícios 9                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

struct habitante{
    char nome[100];
    int idade,sexo,estadoCivil,quantFilhos;
    float salario;
};

void entradaHabitantes(struct habitante[TAMANHO]);

int verificaSexo();
int verificaEstado();

float mediaSalario(struct habitante[TAMANHO]);
int mediaFilhos(struct habitante[TAMANHO]);
void homemJovemMaiorSalario(struct habitante[TAMANHO]);
void mulherJovemMaiorSalario(struct habitante[TAMANHO]);
void mulherIdosaSemFilho(struct habitante[TAMANHO]);

void ordenaVetorIdade(struct habitante[TAMANHO]);

void menu(struct habitante[TAMANHO]);
void verificaOpcao(int,struct habitante[TAMANHO]);

int main(){
    struct habitante sHabitantes[TAMANHO];
    entradaHabitantes(sHabitantes);
    ordenaVetorIdade(sHabitantes);
    menu(sHabitantes);
    system ("pause");
    return 0;
}


void entradaHabitantes(struct habitante sHabitantes[TAMANHO]){
    int i,idade,quantFilhos;
    float salario;
    for(i=0;i<TAMANHO;i++){
        idade=-1;
        salario=-1;
        quantFilhos=-1;
        system("cls");
        printf("  Habitante No %d\n\n",i+1);
        setbuf(stdin, NULL); 
        printf("Digite o nome:\n");
        gets(sHabitantes[i].nome);
        
        while(idade<0){
            setbuf(stdin, NULL); 
            printf("Digite a idade:\n");
            scanf("%d",&idade);
        }
        sHabitantes[i].idade = idade;
                
        setbuf(stdin, NULL); 
        printf("Digite o sexo (m/masculino - f/feminino):\n");
        sHabitantes[i].sexo = verificaSexo();
        
        while(salario<0){
            setbuf(stdin, NULL); 
            printf("Digite o salario:\n");
            scanf("%f",&salario);
        }
        sHabitantes[i].salario = salario;
        
        printf("Digite o estado civil (solteiro, casado, divorciado ou viuvo):\n");
        sHabitantes[i].estadoCivil = verificaEstado();
        
        while(quantFilhos<0){
            setbuf(stdin, NULL); 
            printf("Digite a quantidade de filhos:\n");
            scanf("%d",&quantFilhos);
        }
        sHabitantes[i].quantFilhos = quantFilhos;
    }
    system("cls");    
}

int verificaSexo(){
    char sexo[15];
    
    while (1){
        setbuf(stdin, NULL); 
        gets(sexo);
        strlwr(sexo);
        if((strcmp(sexo,"masculino")==0) || (strlen(sexo)==1 && sexo[0]=='m')){
            return 1;
        }else if((strcmp(sexo,"feminino")==0) || (strlen(sexo)==1 && sexo[0]=='f')){
            return 2;
        }
        printf("Sexo digitado e' invalido!\n  Por favor, digite 'm' ou 'masculino' para masculino e 'f' ou 'feminino' para feminino:\n");
    }
}

int verificaEstado(){
    char estadoCivil[15];
    
    while (1){
        setbuf(stdin, NULL); 
        gets(estadoCivil);
        strlwr(estadoCivil);
        if(strcmp(estadoCivil,"solteiro")==0){
            return 1;
        }else if(strcmp(estadoCivil,"casado")==0){
            return 2;
        }else if(strcmp(estadoCivil,"divorciado")==0){
            return 3;
        }else if(strcmp(estadoCivil,"viuvo")==0){
            return 4;
        }
        printf("Estado civil digitado e' invalido!\n  Por favor, digite solteiro, casado, divorciado ou viuvo:\n");
    }
}

float mediaSalario(struct habitante sHabitantes[TAMANHO]){
    float somaSalarios=0;
    int i;
    for(i=0;i<TAMANHO;i++){
        somaSalarios+=sHabitantes[i].salario;
    }
    return somaSalarios/TAMANHO;
}

int mediaFilhos(struct habitante sHabitantes[TAMANHO]){
    int somaFilhos=0;
    int i,quantPais;
    for(i=0;i<TAMANHO;i++){
        if (sHabitantes[i].estadoCivil!=1){
            somaFilhos+=sHabitantes[i].quantFilhos;
            quantPais++;
        }
    }
    if (quantPais!=0){
        return somaFilhos/quantPais;
    }else{
        return 0;
    }
}

void homemJovemMaiorSalario(struct habitante sHabitantes[TAMANHO]){
    int i,menorIdade=-1,indiceMenor=-1;
    
    /* Primeiramente encontra a idade do homem mais jovem: */
    for (i=0;menorIdade==-1 && i<TAMANHO;i++){
        if(sHabitantes[i].sexo==1){
            menorIdade=sHabitantes[i].idade;
            indiceMenor=i;
        }   
    }

    if(menorIdade==-1){
        printf("Nao existem habitantes homens cadastrados!\n");
        system("pause");
    }else{
        /* Verifica se existem mais homens com aquela idade cadastrada e encontra o maior salario */
        float maiorSalario = sHabitantes[indiceMenor].salario;
        for(i=indiceMenor;sHabitantes[i].idade==menorIdade;i++){
            if(sHabitantes[i].salario>maiorSalario && sHabitantes[i].sexo==1){
                maiorSalario = sHabitantes[i].salario;
                indiceMenor=i;
            }
        }
        printf("O homem mais jovem com maior salario e' %s com um salario de %f.\n",sHabitantes[indiceMenor].nome,sHabitantes[indiceMenor].salario);
        system("pause");
    }
}
void mulherJovemMaiorSalario(struct habitante sHabitantes[TAMANHO]){
    int i,menorIdade=-1,indiceMenor=-1;
    
    /* Primeiramente encontra a idade da mulher mais jovem: */
    for (i=0;menorIdade==-1 && i<TAMANHO;i++){
        if(sHabitantes[i].sexo==2){
            menorIdade=sHabitantes[i].idade;
            indiceMenor=i;
        }   
    }

    if(menorIdade==-1){
        printf("Nao existem habitantes homens cadastrados!\n");
        system("pause");
    }else{
        /* Verifica se existem mais mulheres com aquela idade cadastrada e encontra o maior salario */
        float maiorSalario = sHabitantes[indiceMenor].salario;
        for(i=indiceMenor;sHabitantes[i].idade==menorIdade;i++){
            if(sHabitantes[i].salario>maiorSalario && sHabitantes[i].sexo==2){
                maiorSalario = sHabitantes[i].salario;
                indiceMenor=i;
            }
        }
        printf("A mulher mais jovem com maior salario e' %s com um salario de %f.\n",sHabitantes[indiceMenor].nome,sHabitantes[indiceMenor].salario);
        system("pause");
    }
}
void mulherIdosaSemFilho(struct habitante sHabitantes[TAMANHO]){
    int i,maiorIdadeSemFilhos=-1,encontrado=0;
    for(i=TAMANHO-1;i>=0;i--){
        if(sHabitantes[i].sexo==2 && sHabitantes[i].quantFilhos==0){
            if(encontrado==0){
                printf("A mulher mais idosa sem filhos e' %s com %d anos\n",sHabitantes[i].nome,sHabitantes[i].idade);
                maiorIdadeSemFilhos = sHabitantes[i].idade;
                encontrado=1;
            }else if(sHabitantes[i].idade==maiorIdadeSemFilhos){
                printf("Outra mulher com a mesma idade e sem filhos encontrada: %s com %d anos\n",sHabitantes[i].nome,sHabitantes[i].idade);
            }else{
                break;
            }
        }
    }    
    if(encontrado==0){
        printf("Nao foram cadastradas mulheres!\n");
    }
    system("pause");
}

void menu(struct habitante sHabitantes[TAMANHO]){
    int opcao;
    do{
        setbuf(stdin, NULL);        
        system("cls");
        printf("Escolha uma opcao:\n  1. Calcular a media do salario dos habitantes.\n  2. Calcula a media da quantidade de filhos dos habitantes que nao sao solteiros.\n  3. Exibir o nome e o salário do homem mais jovem que tem o maior salario entre todos os homens.\n  4. Exibir o nome e o salario da mulher mais jovem que tem o maior salario entre todas as mulheres.\n  5. Exibir o nome e a idade da mulher mais idosa que nao tem filho.\n  0. Sair\n\n  Opcao:");
        scanf("%d",&opcao);
    }while(opcao <0 || opcao >5);
    
    /* Verifica qual opção o usuario digitou */
    verificaOpcao(opcao,sHabitantes);
}

void verificaOpcao(int opcao, struct habitante sHabitantes[TAMANHO]){
    system("cls");
    int sair=0;
    if(opcao==1){
        printf("A media dos salarios entre os %d habitantes e' %f.\n",TAMANHO,mediaSalario(sHabitantes));
        system("pause");
    }else if(opcao==2){
        printf("A media da quantidade de filhos entre os habitantes homens nao \nsolteiros e' aprox. %d.\n",mediaFilhos(sHabitantes));
        system("pause");
    }else if(opcao==3){
        homemJovemMaiorSalario(sHabitantes);
    }else if(opcao==4){
        mulherJovemMaiorSalario(sHabitantes);
    }else if(opcao==5){
        mulherIdosaSemFilho(sHabitantes);
    }else if(opcao==0){
        /* Usuario selecionou a opcao de sair */
        char selec='a';
        while (selec != 's' && selec != 'S' && selec != 'n' && selec != 'N'){
            setbuf(stdin, NULL);
            printf("Deseja realmente sair? (<s> para sim e <n> para nao)");
            scanf("%c",&selec);
            system("cls");
        }
        if(selec=='s' || selec=='S')sair=1;
    }
    if(sair!=1){
        menu(sHabitantes);
    }
}

void ordenaVetorIdade(struct habitante sHabitantes[TAMANHO]){
    int i,j,k,menor;
    struct habitante aux;
    for (i=0;i<TAMANHO;i++){
        menor=i;
        for(j=i+1;j<TAMANHO;j++){
            if(sHabitantes[j].idade<sHabitantes[menor].idade){
                menor=j; 
            }
        }
        aux = sHabitantes[i];
        sHabitantes[i] = sHabitantes[menor];
        sHabitantes[menor] = aux;
    }
}
