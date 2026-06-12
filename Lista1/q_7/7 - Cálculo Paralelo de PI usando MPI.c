#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long long n = 0;
    if (rank == 0) {
        scanf("%lld", &n);
    }

    MPI_Bcast(&n, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    double L = 1.0 / (double)n;
    double local_sum = 0.0;

    for (long long i = rank; i < n; i += size) {
        double x = (i + 0.5) * L;
        local_sum += 4.0 / (1.0 + x * x);
    }

    double total_sum = 0.0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("%.10f\n", total_sum * L);
    }

    MPI_Finalize();
    return 0;
}
