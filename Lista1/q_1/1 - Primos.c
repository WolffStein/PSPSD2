#include <stdlib.h>
#include <stdio.h>

#define MAX_TAMANHO 100

int EPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int verificaArrojado(int numero) {
    if (numero == 0) return 1;

    if (!EPrimo(numero)) return 0;

    return verificaArrojado(numero / 10);
}

int ValoresPrimos() {
    int tamanho, temp = 0;
    scanf("%d", &tamanho);

    if (tamanho <= MAX_TAMANHO) {
        int lista[tamanho];

        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &temp);
            lista[i] = temp;
        }

        for (int i = 0; i < tamanho; i++) {
            if (verificaArrojado(lista[i])) {
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
    }

    return 0;
}

int main() {
    ValoresPrimos();
    return 0;
}