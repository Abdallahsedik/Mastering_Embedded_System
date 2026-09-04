#include <stdio.h>
//make multi_dimensional array
//take elements from the user and the size 
//output --> transpoze of the matrix

#define MAX_SIZE 5 
int main(void) {
   int rows, cols;
    float matrix[MAX_SIZE][MAX_SIZE]; 

    printf("Enter number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    // Safety check 
    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        printf("Error: Invalid dimensions. Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("\nEnter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("\nTranspose of the Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%.2f\t", matrix[j][i]);
        }
        printf("\n"); 
    }

    return 0;
}