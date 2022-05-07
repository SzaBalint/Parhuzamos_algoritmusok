#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>
#define N 500

void norma_1(double matrix[N][N]);

void init_matrix(double matrix[N][N]);

void random_nums(double matrix[N][N]);


int main(){

    double matrix[N][N];

    srand(time(NULL));
    init_matrix(matrix);

    //random_nums(matrix);

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    norma_1(matrix);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTime used %lf.",cpu_time_used);

    return 0;
}

//1-es norma számítása
void norma_1(double matrix[N][N]){
    double max = 0;
    double sum = 0;

    #pragma omp parallel
    for(int i=0;i<N;i++)
    {
        sum = 0;
        #pragma omp parallel for reduction (+:sum)
        for(int j=0;j<N;j++)
        {
            sum += matrix[j][i];
        }
        if(sum > max)
            max = sum;
    }
    printf("\nMax: %lf\n",max);
}

void init_matrix(double matrix[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            matrix[i][j]=(double)rand()/RAND_MAX*(30000 - 1) + 1;
        }
    }
}

void random_nums(double matrix[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%.1lf ",matrix[i][j]);
        }
        printf("\n");
    }
}
