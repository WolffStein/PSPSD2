#include <stdio.h>
#include <omp.h>

int main() {
    long long n;
    scanf("%lld", &n);

    double sum = 0.0;
    double L = 1.0 / (double)n;

    #pragma omp parallel for reduction(+:sum) schedule(static)
    for (long long i = 0; i < n; i++) {
        double x = (i + 0.5) * L;
        sum += 4.0 / (1.0 + x * x);
    }

    printf("%.10f\n", sum * L);
    return 0;
}
