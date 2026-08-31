#include <stdio.h>
/*
this program takes n number of elements from user 
store the data in an array  
calculates the average of those numbers 
*/
#define ARR_SIZE 20
int main (void)
{
    float arr[ARR_SIZE]={0};
    int arr_size=0;
    float sum=0;
    printf("Enter The Numbers Of Data:");
    scanf("%d",&arr_size);
    //safety check
    if (arr_size <= 0 || arr_size > ARR_SIZE) {
        printf("Error: Invalid number of elements.\n");
        return 1; 
    }
    
    for(int i=0; i<arr_size ;i++)
    {
        printf("Enter  Number:");
        scanf("%f",&arr[i]);
        sum+= arr[i];
    }

    printf("average=%0.2f",(sum/arr_size));
    return 0; 

}