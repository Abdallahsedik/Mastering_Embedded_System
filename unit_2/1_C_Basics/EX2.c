#include <stdio.h>
/*
EX2:

Write C Program to Print a Integer Entered by a User
i should see the Console as following:
##########Console-output###
Enter a integer: 25
You entered: 25
###########################

######################################################################## 
*/
void main(void )
{
    int num=0;
    printf("##########Console-output### \n ");
    printf("Enter a integer: ");
    scanf("%d",&num); /* Storing a integer entered by user in variable num */
    printf("You entered: %d \n",num );
    printf("########################### \n ########################################################################  ");


}