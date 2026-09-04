#include <stdio.h>

int main(void) {
    int arr[100]; 
    int n=0, search_elem=0;
    int found = 0;

    printf("Enter no of elements : ");
    scanf("%d", &n);

    // Safety check
    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the elements to be searched : ");
    scanf("%d", &search_elem);

    for (int i = 0; i < n; i++) {
        if (arr[i] == search_elem) {
            printf("Number found at the location = %d\n", i + 1);
            found = 1; 
            break;
        }
    }

    if (found == 0) {
        printf("Number not found in the array.\n");
    }

    return 0;
}