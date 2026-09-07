#include <stdio.h>
/*
this program asks user to enter a string   
program find the length of the string then reverse the string 
*/

int main (void)
{
    char name[50];
    int length = 0;
    char temp;

    printf("enter a string: ");
    scanf("%s",name);

    
    while (name[length] != '\0') 
    {
        length++;
    }
     for (int iterator = 0; iterator < length / 2; iterator++) {
        temp = name[iterator];
        name[iterator] = name[length - 1 - iterator];
        name[length - 1 - iterator] = temp;
    }
    printf("length of the string  =%d\n",length);
    printf("reversed  string  =%s",name);

    return 0;
}