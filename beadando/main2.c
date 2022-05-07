#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define N 100000

int tomb[N];
int occurance[10];


void in_between();

void init_array();

void random_nums();

int main(){

    srand(time(NULL));
    init_array();

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    in_between();

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTime used %lf.",cpu_time_used);
    return 0;
}

//intervallumban esõ elemek száma nem párhuzamos programmal
void in_between()
{
	for(int i=0;i<10;i++)
    {
        int interval = 9000+i*1000;
        int interval_end = 10000+i*1000;
        for(int j=0;j<N;j++)
        {
            if(tomb[j] <= interval && tomb[j] >= interval)
                occurance[i]++;
        }
        for(int k=0;k<10000;k++){
        }
    }
	return ;
}

void random_nums(){
    for(int i=0;i<N;i++){
        printf("\n%d ",tomb[i]);
    }
}

void init_array(){
    for(int i=0;i<N;i++){
        tomb[i]=rand();
    }
}
