#include <stdio.h>
#include <stdlib.h>




/*■ Q4:
Write a program in C to print the elements of an array in reverse
order. Test Data :
Input the number of elements to store in the array (max 15) : 5
Input 5 number of elements in the array :
element - 1 : 2
element - 2 : 3
element - 3 : 4
element - 4 : 5
element - 5 : 6
Expected Output :
The elements of array in reverse order are :
element - 5 : 6
element - 4 : 5
element - 3 : 4
element - 2 : 3
element - 1 : 2
*/
#define MAX_SIZE 15

int main()
{
    int arr[MAX_SIZE];
    int n;
    int *ptr;


    printf("Input the number of elements to store in the array (max 15) : ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        n = MAX_SIZE;
    }

    printf("Input %d number of elements in the array :\n", n);
    ptr = arr;

    for (int i = 0; i < n; i++)
    {
        printf("element - %d : ", i + 1);
        scanf("%d", ptr);
        ptr++;
    }

    printf("\nThe elements of array in reverse order are :\n");

    ptr = arr + n - 1;

    for (int i = n; i > 0; i--)
    {
        printf("element - %d : %d\n", i, *ptr);
        ptr--;
    }

    return 0;
}
