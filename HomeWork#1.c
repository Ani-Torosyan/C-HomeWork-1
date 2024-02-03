#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(double *A, int n) 
{
    for (int i = 1; i < n; ++i) 
    {
        double key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) 
        {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

int main(int argc, char **argv) 
{
    if (argc != 4) 
    {
        fprintf(stderr, "Usage: %s [size] [before.txt] [after.txt]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    double *arr = (double *)malloc(n * sizeof(double));

    if (arr == NULL) 
    {
        fprintf(stderr, "Error: failed to allocate memory!\n");
        return 1;
    }

    srand(time(NULL)); 

    for (int i = 0; i < n; ++i) 
    {
        arr[i] = (double)rand() / RAND_MAX;
    }


    FILE *before_file = fopen(argv[2], "w");
    if (before_file == NULL) 
    {
        fprintf(stderr, "Error: couldn't open %s for writing\n", argv[2]);
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; ++i) 
    {
        fprintf(before_file, "%lf ", arr[i]);
    }
    fclose(before_file);

    clock_t start_time = clock();

    insertion_sort(arr, n);

    clock_t end_time = clock();

    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", elapsed_time);

    FILE *after_file = fopen(argv[3], "w");
    if (after_file == NULL) 
    {
        fprintf(stderr, "Error: couldn't open %s for writing\n", argv[3]);
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; ++i) 
    {
        fprintf(after_file, "%lf ", arr[i]);
    }
    fclose(after_file);

    free(arr);
    return 0;
}

//./HomeWork#1.exe 5 before.txt after.txt
