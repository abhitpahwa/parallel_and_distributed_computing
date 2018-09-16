#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);
    int num_processor;
    MPI_Comm_size(MPI_COMM_WORLD, &num_processor);
    int process_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    printf("Hello abhit from processor %s, rank %d out of %d processors\n",
    MPI_Finalize();
}

