#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2=0;
    bool dont =true;
    printf("Adjon meg 2 egesz szamot vesszovel elvalasztva:\n");
    do{
            if((scanf("%d,%d",&num1,&num2))!=2 || num1<num2 || num1==num2){
            printf("Hibas beolvasas!\n");
            dont=true;
            }
            else{
                dont=false;
            }
    }while(dont!=false);

    int randomnumber;
    randomnumber = (rand() % num1)+num2;
    printf("A generealt szam: %d\n", randomnumber);
    return 0;
}
