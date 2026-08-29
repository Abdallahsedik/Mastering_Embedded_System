#include <stdio.h>
#define SIZE_OF_ARRAY     10
void Print_Array(int * Element, int Number_of_elements);
void Scan_Array(int * Element, int Number_of_elements);

void main (void)
{
    int Arr_std[SIZE_OF_ARRAY];
    Scan_Array(&Arr_std[0], SIZE_OF_ARRAY);
    Print_Array(&Arr_std[0], SIZE_OF_ARRAY);


}

void Print_Array(int * Element, int Number_of_elements)
{
    int * ptr=Element;
    for(int iterator = 0; iterator<Number_of_elements ;iterator++)
    {   
         printf("student %d degree is : %d \n", (iterator + 1),*(ptr + iterator));
    }
}
void Scan_Array(int * Element, int Number_of_elements)
{
    int * ptr=Element;
    for(int iterator = 0; iterator<Number_of_elements ;iterator++)
    {   
        printf("\n Enter element %d: ", (iterator + 1));
         scanf("%d", (ptr + iterator));

    }

}