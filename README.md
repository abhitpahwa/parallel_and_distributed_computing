# parallel_and_distributed_computing
codes related to parallel and ditributed computing
all the external files required in code files are available in the repository
- pdc_lab1_a.c : print prime numbers from 1 to 500 and 501 to 1000 using 2 threads
- pdc_lab1_b.c : print number of vowels and consonants in a given text file
- pdc_lab1_c.c : print the result of matrix addition and matrix subtraction of size 200 * 200 (matrices read from files)
- pdc_lab1_d.c : print the reverese of a string and another string created by shifting the letter to next letter
- pdc_lab2_a.c : print numbers from 1 to 10000 using omp
- pdc_lab2_b.c : print the result of addition of 2 matrices using omp
- pdc_lab2_c.c : print the result of addition of 2 matrices using omp and collapse
- pdc_lab2_d.c : print the result of addition of 2 matrices stored in text files using omp
- pdc_lab2_e.c : print the result of addition of 2 matrices stored in text files using omp and collapse
- pdc_lab2_f.c : print the result of addition of 2 matrices stored in text files using omp and dynamic scheduling
- pdc_lab2_g.c : print the result of addition of 2 matrices stored in text files using omp and guided scheduling
- pdc_lab2_h.c : print the result of addition of 2 matrices stored in text files using omp and static scheduling
- pdc_lab3_a.c : print the result of count of vowels and consonants in a text fle using omp
- pdc_lab3_b.c : print the result of summation of elements of vectors using omp sections
- pdc_lab3_c.c : print the result of summation of elements of vectors using omp reduction
- pdc_lab4_a.c : print the maximum value of a vector using omp reduction
- pdc_lab4_b.c : print the words occuring more than twice and their count in a text file using omp reduction
- pdc_lab5_a.c : producer-consumer problem using mutex, wait, signal
- pdc_lab5_b.c : producer-consumer problem using omp
- pdc_lab5_c.c : reader-writer problem using semaphores
- pdc_lab5_d.c : reader-writer problem using omp
- pdc_lab6_a.c : producer-consumer problem using sections and critical in omp
- pdc_lab6_b.c : producer-consumer problem using sections and locks in omp
- pdc_lab6_c.c : create 2 child process; use one to print prime numbers and other for armstrong numbers from 1 to 1000
- pdc_lab6_d.c : print the prime numbers using sequential code of sieve of eratosthenes
- pdc_lab7_a.c : print the result of multiplication of 2 matrices using sequential code
- pdc_lab7_b.c : print the result of multiplication of 2 matrices using omp with outermost loop parallelized
- pdc_lab7_c.c : print the result of multiplication of 2 matrices using omp with outer 2 loops parallelized 
- pdc_lab7_d.c : print the result of multiplication of 2 matrices using omp with all loops parallelized
- pdc_lab7_e.c : print the prime numbers using sieve of eratosthenes with help of omp
- pdc_lab7_f.c : print the prime numbers using sieve of eratosthenes with help of pthreads
- pdc_lab8_a.c : print the result of multiplication of 2 matrices using omp collapse
- pdc_lab8_b.c : same as pdc_lab7_d.c with options to choose size of matrix
- pdc_lab8_c.c : print hello world using mpi 
- pdc_lab9_a.c : using mpi to execute the following problem --> Process P0 sends a number to P1 and P1 checks whether it’s an odd number or even number, and sends the result to P2.
- pdc_lab9_b.c : using mpi to execute the following problem --> P0 sends a number to P1, P2, P3. P1 checks whether it’s an odd number or even number and sends the result to P4. P2 checks whether the number is prime or not, and sends the result to P5. P3 checks whether the number is Armstrong or not and sends the result to P6.
- pdc_lab9_c.c : using mpi to execute the following problem --> P0 sends a string to P1,P2. P1 counts the vowels from the string and sends the count to P3. P2 counts the consonants and sends the count to P4.
- pdc_lab10_a.c : using mpi to broadcast message to other processes using MPI_Bcast
- pdc_lab10_b.c : using mpi to scatter elements of array to all processes using MPI_Scatter
- pdc_lab10_c.c : using mpi to gather elements from other processes into an array in P0 using MPI_Gather 
- pdc_lab11_a.c : using mpi to scatter elements of array to all processes and printing name of digits in a number
- pdc_lab11_b.c : using mpi to gather elements of array from other processes into an array in P0 and then sorting the array
- create_matrix_100* 100.py : python script to create 100 * 100 matrices 
- create_matrix_200* 200.py : python script to create 200 * 200 matrices 
- create_matrix_300* 300.py : python script to create 300 * 300 matrices
- matrix_100* 100_1.c : text file of matrix 1 created using create_matrix_100* 100.py
- matrix_100* 100_2.c : text file of matrix 2 created using create_matrix_100* 100.py
- matrix_200* 200_1.c : text file of matrix 1 created using create_matrix_200* 200.py
- matrix_200* 200_2.c : text file of matrix 2 created using create_matrix_200* 200.py
- matrix_300* 300_2.c : text file of matrix 3 created using create_matrix_300* 300.py
- matrix_300* 300_2.c : text file of matrix 3 created using create_matrix_300* 300.py
- textfile.txt :  random text file, text inside can be edited.
- textfile1.txt : random text file, the text inside can be edited.
- name.txt : text file containing name, the text inside can be edited

COMPILATION and EXECUTION:
- for general c program : gcc filename.c && ./a.out
- for openmp : gcc -fopenmp filename.c && ./a.out
- for mpi : mpicc -o object_file_name filename.c && mpirun -np num_copies_code -host host_ip1,host_ip2 ./object_file_name
