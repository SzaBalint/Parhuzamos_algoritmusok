#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define N 10000

const int N_THREADS = 1;
int tomb[N];
int occurance[10];


typedef struct task{
    int left;
    int right;
}Task;

void in_between(Task* task);

void init_array();

void random_nums();

int main()
{
    srand(time(NULL));
    init_array();

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    Task tasks[N_THREADS];
    pthread_t threads[N_THREADS];

    int left = 5000;
    int right = 20000;
    int number = (right-left)/N_THREADS;
    int number_constant = number;
    int number_2 = 0;

    for(int i=0;i<N_THREADS;i++)
    {
        tasks[i].left = number_2;
        tasks[i].right = number;
        number_2 += number_constant;
        number += number_constant;
    }

    for(int i=0;i<N_THREADS;i++)
    {
        pthread_create(&threads[i],NULL,in_between,&tasks[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    int bal = 5000;
    int sum = 0;
    for(int i=0;i<10;i++)
    {
        printf("\nThere are %d number between %d - %d\n", occurance[i], bal, bal+1000);
        sum += occurance[i];
        bal+=1000;
    }

    printf("\nNumbers that aren't in the specified intervals %d",N-sum);
    printf("\nTime used %lf.",cpu_time_used);

    return 0;
}

void in_between(Task* task)
{
    int index = 0;
    for(int i=task->left;i<task->right;i++)
    {
        for(int j=5000;j<=14000;j+=1000)
        {
            if(j == 5000)
                index = 0;
            if(tomb[i] >= j && tomb[i] <= j+1000)
            {
                occurance[index]++;
            }
            index++;
        }
    }
    for(int i=0;i<100000;i++){
    }
    for(int i=0;i<100000;i++){
    }
	return ;
}

void init_array(){
    for(int i=0;i<N;i++){
        tomb[i]=rand();
    }
}

void random_nums(){
    for(int i=0;i<N;i++){
        printf("\n%d ",tomb[i]);
    }
}