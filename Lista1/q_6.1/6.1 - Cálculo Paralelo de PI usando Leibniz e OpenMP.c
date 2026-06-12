#include <stdio.h>
#include <omp.h>

int main() {
    long long n;
    scanf("%lld", &n);

    double sum = 0.0;

    /*
     * Serie de Leibniz:
     * pi = 4 * sum_{k=0}^{N-1} (-1)^k / (2k + 1)
     *    = 4 * (1 - 1/3 + 1/5 - 1/7 + ...)
     */
    #pragma omp parallel for reduction(+:sum) schedule(static)
    for (long long k = 0; k < n; k++) {
        double term = 1.0 / (2.0 * k + 1.0);
        if (k % 2 == 0)
            sum += term;
        else
            sum -= term;
    }

    printf("%.10f\n", 4.0 * sum);
    return 0;
}
