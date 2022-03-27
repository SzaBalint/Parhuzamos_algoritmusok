#include <stdio.h>
#include <stdlib.h>

int count_primes(int n)
{
    int num;
    int i;
    int oszto=0;
    int count=0;

    for(num=2;num<=n; num++)
    {
        oszto = 0;
            for(i=1; i<=num; i++)
            {
                if(num % i == 0)
                {
                    oszto++;
                }
            }
        if (oszto == 2)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    printf("%d", count_primes(1000));
    return 0;
}
