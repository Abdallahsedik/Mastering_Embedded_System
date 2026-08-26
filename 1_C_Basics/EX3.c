#include <stdio.h>
/*
Write C Program to Add Two Integers

i should see the Console as following:
##########Console-output###
Enter two integers: 12
11
Sum: 23
###########################

########################################################################
*/
void main(void )
{
    int num1=0 ,num2=0, sum=0 ;
      
    printf("##########Console-output### \n ");
    printf("Enter number 1 : ");
    scanf("%d",&num1  ); /* Storing a integer entered by user in variable num */
    printf("\n Enter number 2 : ");
    scanf("%d",&num2  ); /* Storing a integer entered by user in variable num */
    sum =num1 +num2;
    printf("Sum: %d", sum );
    printf("########################### \n ########################################################################  ");


}