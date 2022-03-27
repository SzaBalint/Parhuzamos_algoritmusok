#include <stdio.h>
#include <stdlib.h>

void generate_array(double tomb[],int n,double low, double high)
{
    int i;
    for(i =0;i<n;i++)
    {
        tomb[i]= rand()/(double)RAND_MAX*(high-low)+low;
    }
}

void sort(double tomb[],int n)
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

int binary_search(double tomb[], int left, int right, double x)
{
    if (right >= left) {
        int middle = left + (right - left) / 2;

        if (tomb[middle] == x)
            return middle;

        if (tomb[middle] > x)
            return binaris_kereses(tomb, left, middle - 1, x);

        return binaris_kereses(tomb, middle + 1, right, x);
    }
    return -1;
}


void print_out(double tomb[],int n)
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

    generate_array(tomb,n,1.0,10.0);
    print_out(tomb,n);

    printf("\n");

    sort(tomb,n);
    printf("Rendezett tomb: \n");
    print_out(tomb,n);

    double x=7.719443;

    int result = binary_search(tomb, 0, n - 1, x);
    (result == -1)
        ? printf("Az elem nincs a tombben!")
        : printf("Az elem benne van a tombben az %d. indexxel", result);

    return 0;
}
