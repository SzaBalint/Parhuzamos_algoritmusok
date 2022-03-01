#include <stdio.h>
#include <stdlib.h>

int max_rekurziv(int tomb[],int n)
{
    int max = 0;
    int i=n-1;
    do{
        if(max<tomb[i])
        {
            max=tomb[i];
        }
        i--;
    }while(i>=0);
    return max;
}

int min_rekurziv(int tomb[],int n)
{
    int min = tomb[n];
    int i=n-1;
    do{
        if(min>tomb[i])
        {
            min=tomb[i];
        }
        i--;
    }while(i>=0);
    return min;
}

void kiir(int tomb[],int n)
{
    printf("\n");
    for(int i = 0;i<n;i++){
        printf("%d\n",tomb[i]);
    }
}

int max(int tomb[],int n)
{
    int max =0;
    for(int i=0;i<n;i++){
        if(tomb[i]>max){
            max=tomb[i];
        }
    }
    return max;
}

int min(int tomb[],int n)
{
    int min =tomb[0];
    for(int i=0;i<n;i++){
        if(tomb[i]<min){
            min=tomb[i];
        }
    }
    return min;
}

int osszeg(int tomb[],int n)
{
    int osszeg=0;
    for(int i =0;i<n;i++)
    {
        osszeg+=tomb[i];
    }
    return osszeg;
}

int main()
{   
    int n=0;
    printf("Adja meg a tomb meretet:\n");
    scanf("%d",&n);
    int tomb[n];
    for(int i =0;i<n;i++)
    {
        tomb [i] = rand()%501+500;
    }      
    
    kiir(tomb,n);

    printf("A tomb elemeinek osszege: \n");
    printf("%d\n",osszeg(tomb,n));

    printf("A tombnek a max eleme: \n");
    printf("%d\n",max(tomb,n));

    printf("A tombnek a min eleme: \n");
    printf("%d\n",min(tomb,n));

    printf("A tombnek a max elem rekurzivan: \n");
    printf("%d\n",max_rekurziv(tomb,n));

    printf("A tombnek a min eleme rekurzivan: \n");
    printf("%d\n",min_rekurziv(tomb,n));
    return 0;
}