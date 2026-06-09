#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int **matriz;


int* montalinha(int n) {
    int *coluna = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &coluna[i]); 
    }
    return coluna;
}


int **montamatriz(int linhas, int colunas){
    matriz = malloc(linhas * sizeof(int*));
    for(int i = 0; i < linhas; i++){
        matriz[i] = montalinha(colunas);
    }
    return matriz;
}

double **produtomatriz(int **A, int **B, int m, int k, int n) {
    double **C = malloc(m * sizeof(double*));
    for (int i = 0; i < m; i++) {
        C[i] = calloc(n, sizeof(double));
    }

    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < k; p++) {
                C[i][j] += (double)A[i][p] * B[p][j];
            }
        }
    }
    return C;
}


int main(){
    int m,k,n;
    scanf("%d %d %d", &m,&k,&n);
    int **A = montamatriz(m,k);
    int **B = montamatriz(k,n);
    double **C = produtomatriz(A,B,m,k,n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }
}
