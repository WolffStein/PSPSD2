#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int seed = 0, n = 0;
    if (rank == 0) {
        scanf("%d", &seed);
        scanf("%d", &n);
    }

    MPI_Bcast(&seed, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    srand(seed);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    long long local_sum = 0;
    for (int i = rank; i < n; i += size)
        local_sum += arr[i];
    free(arr);

    long long total_sum = 0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
        printf("%lld\n", total_sum);

    MPI_Finalize();
    return 0;
}
