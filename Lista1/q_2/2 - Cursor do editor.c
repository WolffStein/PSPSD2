#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS  1000
#define MAX_COLUNAS 1001


int Cursor(char texto[][MAX_COLUNAS],int num, int linha, int col_desejada){
    char cmd;

    while(scanf(" %c", &cmd) != EOF){
        if(cmd == 'j'){
            if (linha < num - 1){
                linha++;
            }
        }
        
        if(cmd == 'k'){
            if (linha > 0){
                linha--;
            }
        }

        int tamanho = strlen(texto[linha]);
        int col_atual = col_desejada;
        
        if(col_atual > tamanho){
            col_atual = tamanho;
        }
        printf("%d %d %c\n", linha + 1, col_atual, texto[linha][col_atual - 1]);
    }
}

int TextoFunc() {
    int num;
    char texto[MAX_LINHAS][MAX_COLUNAS];

    scanf("%d", &num);
    getchar();  // consome o \n deixado pelo scanf

    for (int i = 0; i < num; i++) {
        fgets(texto[i], MAX_COLUNAS, stdin);
        texto[i][strcspn(texto[i], "\n")] = '\0';
    }

    int linha, col_desejada;
    scanf("%d %d", &linha, &col_desejada);
    linha--;  // converte para 0-indexed

    Cursor(texto, num, linha, col_desejada);
}


int main(){
    TextoFunc();
    return 0;
}
