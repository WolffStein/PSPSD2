#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int **board;

int quadradoperfeito(int n);

void montamatriz(int n){
    int valor;
    board = malloc(n * sizeof(int*));
    for (int i = 0; i< n; i++){
        board[i] = malloc (n * sizeof(int));
        for(int j = 0; j< n; j++) {
            scanf("%d",&board[i][j]);
        }
    }
}

int checalinha(int linha, int n){
    int *vistos = calloc(n+1,sizeof(int));

    for(int j=0; j < n; j++){
        int val = board[linha][j];
        if(vistos[val]){
        free(vistos);
        return 0;
        }
        vistos[val] = 1;
    }
    free(vistos);
    return 1;
}


int checacoluna(int coluna, int n){
    int *vistos = calloc(n+1,sizeof(int));

    for(int i=0; i < n; i++){
        int val = board[i][coluna];
        if(vistos[val]){
        free(vistos);
        return 0;
        }
        vistos[val] = 1;
    }
    free(vistos);
    return 1;
}

int quadradoperfeito(int n){
    for(int i = 1; i*i<=n;i++){
        if(i*i == n){
            return i;
        }
    }
    return 0;
}

int checaBloco(int bloco, int n) {
    int *vistos = calloc(n+1, sizeof(int));
    int sqrtN = quadradoperfeito(n);

    int linha_inicio = (bloco / sqrtN) * sqrtN;
    int coluna_inicio = (bloco % sqrtN) * sqrtN;

    for (int i = linha_inicio; i < linha_inicio + sqrtN; i++) {
        for (int j = coluna_inicio; j < coluna_inicio + sqrtN; j++) {
           int val = board[i][j];
           if(vistos[val]){
            free(vistos);
            return 0;
           }
           vistos[val] = 1;
        }
    }
    free(vistos);
    return 1;
}



int main(){
    int n;
    scanf("%d",&n);
    montamatriz(n);

    int *row_valid = calloc(n, sizeof(int));
    int *col_valid = calloc(n, sizeof(int));
    int *block_valid = calloc(n, sizeof(int));

   #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        row_valid[i]   = checalinha(i, n);
        col_valid[i]   = checacoluna(i, n);
        block_valid[i] = checaBloco(i, n);
    }
    
    int valido = 1;
    for (int i = 0; i < n; i++) {
        if (!row_valid[i] || !col_valid[i] || !block_valid[i]) {
            valido = 0;
            break;
        }
    }

    printf("%s\n", valido ? "Valido" : "Invalido");

    free(row_valid);
    free(col_valid);
    free(block_valid);
    return 0;
}