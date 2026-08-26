#include <stdio.h>
/*
EX7:
it is an interview trick

Write Source Code to Swap Two Numbers without temp variable.
#############################
########################################################################
*/
void main(void )
{
    int num1=0  ,num2 =0 , temp=0; 
     printf("##########Console-output### \n ");
    printf("Enter number 1 : ");
    scanf("%d",&num1  ); /* Storing a integer entered by user in variable num */
    printf("\n Enter number 2 : ");
    scanf("%d",&num2  ); /* Storing a integer entered by user in variable num */
    
    num1= num1 ^num2;
    num2= num1 ^num2;
    num1= num1 ^num2;

    printf(" \n After swapping, value of a = %d ",num1  );
    printf(" \n After swapping, value of b = %d ",num2  );

    printf("\n ########################### \n ########################################################################  ");


}

