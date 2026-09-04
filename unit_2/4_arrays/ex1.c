#include <stdio.h>
//make 2 multi_dimensional arrays (2*2)
//take elements from the user 
//output --> sum of tho matrix 

int main(void) {
    float m1[2][2], m2[2][2];

    // Read first matrix
    printf("Enter 4 elements for the 1st matrix:\n");
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < 2; j++) 
            scanf("%f", &m1[i][j]);

    // Read second matrix
    printf("Enter 4 elements for the 2nd matrix:\n");
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < 2; j++) 
            scanf("%f", &m2[i][j]);

    // Calculate and print the sum
    printf("\nSum of the two matrices:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%.2f\t", m1[i][j] + m2[i][j]);
        }
        printf("\n");
    }

    return 0;
}