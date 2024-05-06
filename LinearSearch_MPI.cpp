#include <iostream>
#include "mpi.h"

using namespace std;

int main() {
    int rank, size, element;
    int vector[] = { 1, 2, 4, 7, 9, 12, 14, 17, 17, 17, 17, 30, 32, 35, 38, 40 };
    int vectorSize = sizeof(vector) / sizeof(vector[0]);

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        cout << "Scrieti termenul pe care il cautati: ";
        cin >> element;

        for (int processID = 1; processID < size; processID++)
            MPI_Send(&element, 1, MPI_INT, processID, 1, MPI_COMM_WORLD);
    }
    else {
        MPI_Recv(&element, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    int start = (rank * vectorSize) / size;
    int end = ((rank + 1) * vectorSize) / size;

    for (int i = start; i < end; i++) {
        if (i < vectorSize && vector[i] == element) {
            cout << "Numarul a fost gasit la pozitia " << i << "\n";
        }
    }

    MPI_Finalize();

}