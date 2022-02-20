#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start, end;
    int randomnumber1,randomnumber2;
    int eredmeny;

    randomnumber1= rand();
    randomnumber2= rand();
    start = clock();
    printf("Adja meg az eredmenyt: %d+%d=",randomnumber1,randomnumber2);
    scanf("%d",&eredmeny);
    end = clock();
    if(eredmeny!=randomnumber1+randomnumber2)
    {
        printf("Az eredmeny hibas!\n");
    }
    else{
        printf("Az eredmeny helyes!\n");
    }
    double elteltido = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Ennyi ideig tartott kiszamolni: %.lf",elteltido);
    return 0;
}