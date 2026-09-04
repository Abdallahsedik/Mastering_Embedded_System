#include <stdio.h>
/*
Write C Program to Multiply two Floating Point Numbers
i should see the Console as following:
##########Console-output###

###########################
Enter two numbers: 2.4
1.1
Product: 2.640000
########################################################################
*/
void main(void )
{
    float  num1=0 ,num2=0, sum=0 ;
      
    printf("##########Console-output### \n ");
    printf("Enter number 1 : ");
    scanf("%f",&num1  ); /* Storing a integer entered by user in variable num */
    printf("\n Enter number 2 : ");
    scanf("%f",&num2  ); /* Storing a integer entered by user in variable num */
    sum =num1 *num2;
    printf("Sum: %f", sum );
    printf("########################### \n ########################################################################  ");


}