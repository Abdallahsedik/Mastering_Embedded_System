#include <stdio.h>
//1-make  array
//2-take element's size from the user
//3- make the array elements from 1 to n
//4- user choose the position then the number   
//output --> print final array

#define MAX_SIZE 20
int main(void) {
    int n, pos, new_number;
    int arr[MAX_SIZE]; 
   
    // 2- Take element's size from the user
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    // Safety check 
    
    if (n <= 0 || n > MAX_SIZE) 
    {
        printf("Error: Invalid size.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    printf("Initial array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nEnter the position you want to change (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Error: Invalid position.\n");
        return 1;
    }
    //Shift elements
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    // Increase the size 
    n++;
    
    printf("Enter the new number: ");
    scanf("%d", &new_number);
    arr[pos - 1] = new_number;

    // Output --> print final array
    printf("\nFinal array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}