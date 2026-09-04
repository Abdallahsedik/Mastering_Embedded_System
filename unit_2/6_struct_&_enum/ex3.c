#include <stdio.h>

#define PI 3.14
#define AREA(r) (PI * r * r)   

int main(void)
{
    int radius;
    printf("Enter the radius: ");
    scanf("%d", &radius);
    
    printf("\n Area=%.2f\n", AREA(radius));
    
    return 0;
}