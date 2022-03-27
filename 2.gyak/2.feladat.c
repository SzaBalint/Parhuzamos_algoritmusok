#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void is_unique(int * tomb){
    bool dont =false;
    for(int i = 0; i < 10000; i++) {
        for(int j = i + 1; j < 10000; j++) {
            if(tomb[i] == tomb[j])
                printf("%d\n", tomb[j]);
                dont =true;
            }
    }
    if(dont==false){
        printf("A osszes elem kulonbozik!\n");
    }
    else{
        printf("Nem mindegyik elem kulombozik");
    }
 }

int main()
{

int tomb[10000];
clock_t start, end;

start = clock();

for (int i = 0; i < 10000 ;i++) {
    tomb[i] = rand();
}

for(int i = 0;i<10000;i++)
    {
          for(int j = i + 1; j < 10000; j++) {
                if(tomb[j] == tomb[i])
                {
                    tomb[j] = rand();
                }
            }
 }

    end = clock();

    /*for(int j =0; j<10000 ; j++){
    printf("%d, ",tomb[j]);
    }*/
    double elteltido = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nEnnyi ideig tartott kiszamolni: %lf\n",elteltido);

    egyedi(tomb);
    return 0;
}
