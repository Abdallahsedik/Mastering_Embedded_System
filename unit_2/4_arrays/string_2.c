#include <stdio.h>
/*
this program asks user to enter a string   
program find the length of the string
*/

int main (void)
{
    char name[50];
    int length = 0;

    printf("enter a string: ");
    scanf("%s",name);

    
    while (name[length] != '\0') 
    {
        length++;
    }
    printf("length of the string  =%d",length);

    return 0;
}