#include <stdio.h>
/*
this program asks user to enter a string  and char 
program checks how many times that char is repeated in the string entered by user 

*/

int main (void)
{
    char name[50];
    char c;
    int i = 0,repeated=0;

    printf("enter a string: ");
    scanf("%s",name);

    printf("enter a char: ");
    scanf(" %c",&c);
    
    while (name[i] != '\0') {
        if (name[i]==c)
        {
            repeated++;
        }
        else
        {

        }
        i++;
    }
    printf("freq of %c =%d",c,repeated);

return 0;
}