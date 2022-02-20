#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomnumber;
    randomnumber = (rand() % 501)+500;
    printf("%d\n", randomnumber);
    return 0;
}