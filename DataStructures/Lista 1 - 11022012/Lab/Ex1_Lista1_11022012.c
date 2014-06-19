/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//* 					   */
/* Exercicio  01 - Lista de Exercícios 1                   */
/* CC3651 --2012    --turma 620    						   */
/***********************************************************/

#include <stdio.h>

int main(){
    int qBlocos;
    scanf("%d\n",&qBlocos);
    int i;
    for(i=0; i<qBlocos;i++){
        double total = 0;
        int kElementos;
        scanf("%d\n",&kElementos);
        int j;
        for(j=0;j<kElementos;j++){
            char op;
            int valor;
            scanf("%c%d\n",&op,&valor);
            if(op=='+'){
                total = total +valor;
            }else if(op=='-'){
                total = total - valor;
            } 
        }
        printf("%.0lf\n",total);
    } 
    
    
    return 0;
}
