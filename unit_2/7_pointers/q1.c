#include <stdio.h>
#include <stdlib.h>

/*■ Q1:
Write a program in C to demonstrate how to handle the pointers
in the program.
Expected Output :
Address of m : 0x7ffcc3ad291c
Value of m : 29

Now ab is assigned with the address of m.
Address of pointer ab : 0x7ffcc3ad291c
Content of pointer ab : 29

The value of m assigned to 34 now.
Address of pointer ab : 0x7ffcc3ad291c
Content of pointer ab : 34

The pointer variable ab is assigned with the
value 7 now.
Address of m : 0x7ffcc3ad291c
Value of m : 7
*/


int main()
{
    int m=29;
    int * ab=&m;

    printf("\n Address of m : %p ",&m);
    printf("\n Value of m : %d",m);

    printf("\n Now ab is assigned with the address of m.");

    printf("\n Address of pointer ab  : %p",ab);
    printf("\n Content of pointer ab: %d",*ab);

    m=34;
    printf("\n The value of m assigned to 34 now.");

    printf("\n Address of pointer ab  : %p",ab);
    printf("\n Content of pointer ab: %d",*ab);

    *ab=7;
    printf("\n The pointer variable ab is assigned with the value 7 now.");
    printf("\n Address of m : %p",&m);
    printf("\nValue of m : %d",m);


    return 0;
}
