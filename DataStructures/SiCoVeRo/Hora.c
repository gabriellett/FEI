#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    time_t     now;
    struct tm  ts;
    char       buf[80];
 do{
      now = time(NULL); // Obtem os dados do SO
      ts = *localtime(&now); // Formata os dados no formato struct tm
         printf("%02d:%02d:%02d\n", ts.tm_hour, ts.tm_min, ts.tm_sec); // imprime a hora
         system("pause");
         system("cls"); // limpa a tela
    }while(1); // loop infinito
}
