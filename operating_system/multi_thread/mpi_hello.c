#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {

	MPI_Init(NULL, NULL);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if (world_size < 2) {
		MPI_Abort(MPI_COMM_WORLD, 1);
	}
	
	int number;

	if (world_rank == 0) {
		number = -1;
		for (int rank = 1; rank <= 3; rank++) {
			MPI_Send(&rank, 1, MPI_INT, rank, 0, MPI_COMM_WORLD);
		}
	} else {
		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process %d received number %d from process 0\n", world_rank, number);
	}

	MPI_Finalize();
	return 0;
}
