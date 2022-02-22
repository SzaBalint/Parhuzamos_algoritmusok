#include <stdio.h>
#include <stdlib.h>

int main()
{
    int szam1,szam2=0;
    int dont =0;
    printf("Adjon meg 2 egesz szamot vesszovel elvalasztva:\n");
    do{
            if((scanf("%d,%d",&szam1,&szam2))!=2 || szam1<szam2 || szam1==szam2){
            printf("Hibas beolvasas!\n");
            dont=0;
            }
            else{
                dont=1;
            }
    }while(dont!=1);

    int randomnumber;
    randomnumber = (rand() % szam1)+szam2;
    printf("A generealt szam: %d\n", randomnumber);
    return 0;
}