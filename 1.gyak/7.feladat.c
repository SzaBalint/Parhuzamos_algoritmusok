#include <stdio.h>
#include <stdlib.h>

int count(int n)
{
    int szam;
    int i;
    int oszto=0;
    int db=0;

    for(szam=2;szam<=n; szam++)
    {
        oszto = 0;
            for(i=1; i<=szam; i++)
            {
                if(szam % i == 0)
                { 
                    oszto++; 
                }
            }
        if (oszto == 2)
        { 
            db++;
        }  
    }
    return db;
}

int main()
{
    printf("%d", count(1000));
    return 0;
}