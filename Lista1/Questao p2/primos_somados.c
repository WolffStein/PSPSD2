#include <stdio.h>
#include <math.h>
#include <omp.h>

int eh_primo(long long n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    long long *nums = malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++)
        scanf("%lld", &nums[i]);

    long long soma = 0;

    #pragma omp parallel for reduction(+:soma)
    for (int i = 0; i < N; i++)
        if (eh_primo(nums[i]))
            soma += nums[i];

    printf("%lld\n", soma);

    free(nums);
    return 0;
}