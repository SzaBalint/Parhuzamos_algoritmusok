#include <stdio.h>
#include <stdlib.h>

void tomb_generalas(double tomb[],int n,double low, double high)
{
    
    for(int i =0;i<n;i++)
    {
        tomb[i]= rand()/(double)RAND_MAX*(high-low)+low;
    }
}

void rendezes(double tomb[],int n)
{
    double temp;
     for (int i = 0; i <= n ; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (tomb[j] > tomb[j + 1])
            {
                temp = tomb[j];
                tomb[j] = tomb[j + 1];
                tomb[j + 1] = temp;
            }  
        }
    } 
}

/*void rendezett_e(int tomb[],n){
    for(int i = 0;i<n;i++){

    }
}*/

int binaris_kereses(double tomb[], int l, int r, double x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        if (tomb[mid] == x)
            return mid;
     
        if (tomb[mid] > x)
            return binaris_kereses(tomb, l, mid - 1, x);
  
        return binaris_kereses(tomb, mid + 1, r, x);
    }
    return -1;
}


void kiir(double tomb[],int n)
{
     for(int i =0;i<n;i++)
    {
        printf("%lf\n",tomb[i]);
    }
}

int main()
{   
    int n=0;
    printf("Adja meg a tombnek a meretet:\n");
    scanf("%d",&n);
    double tomb[n];
    
    tomb_generalas(tomb,n,1.0,10.0);
    kiir(tomb,n);
   
    printf("\n");
    
    rendezes(tomb,n);
    printf("Rendezett tomb: \n");
    kiir(tomb,n);

    double x=7.719443;

    int result = binaris_kereses(tomb, 0, n - 1, x);
    (result == -1)
        ? printf("Az elem nincs a tombben!")
        : printf("Az elem benne van a tombben az %d. indexxel", result);

    return 0;
}