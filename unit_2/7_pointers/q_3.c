#include <stdio.h>
#include <stdlib.h>


/*■ Q3:
Write a program in C to print a string in reverse using a pointer
The Alphabets are :
Test Data :
Input a string : w3resource
Expected Output :
Pointer : Print a string in reverse order :
------------------------------------------------
Input a string : w3resource
Reverse of the string is : ecruoser3w
*/


#define Array_size 50

int main()
{
    char str[Array_size] = {0};
    char *ptr = str;
    char temp = '\0'; 
    char *rev_ptr = str;

    printf("Input a string : ");
    scanf("%s", str);

    while (*ptr != '\0') 
    {
        ptr++;
    }

    ptr--;

   
    while (rev_ptr < ptr) 
    {
        temp = *rev_ptr;
        *rev_ptr = *ptr;
        *ptr = temp;

        
        rev_ptr++;
        ptr--;
    }

    printf("Reverse of the string is : %s\n", str);

    return 0;
}

