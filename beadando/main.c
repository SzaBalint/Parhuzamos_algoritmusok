#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define N 100000

const int N_THREADS = 10;
int tomb[N];


typedef struct task{
    int left;
    int right;
	int occur;
}Task;

void in_between(Task* task);

void init_array();

void random_nums();

int main()
{
    srand(time(NULL));
    init_array();
    //random_nums();

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    Task tasks[N_THREADS];
    pthread_t threads[N_THREADS];
    int left = 9000;
    int right = 10000;

    for(int i=0;i<N_THREADS;i++)
    {
        tasks[i].left = left;
        tasks[i].right = right;
        tasks[i].occur = 0;
        left+=1000;
        right+=1000;
    }

    for(int i=0;i<N_THREADS;i++)
    {
        pthread_create(&threads[i],NULL,in_between,&tasks[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    int sum = 0;

    for(int i=0;i<N_THREADS;i++)
    {
        printf("\nThere are %d numbers between %d and %d.\n", tasks[i].occur,tasks[i].left,tasks[i].right);
        sum+= tasks[i].occur;
    }

    printf("\nNumbers that aren't in the specified intervals %d",N-sum);
    printf("\nTime used %lf.",cpu_time_used);

    return 0;
}

void in_between(Task* task)
{
	for(int i=0;i<N;i++){
        if(tomb[i] >= task->left && tomb[i] <= task->right){
           task->occur++;
        }
    }
    for(int i=0;i<10000;i++){
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
