#include <stdio.h>
/*
c program to add two sidtances (in inch- feet )using struct 
*/

typedef struct 
{
    int   feet;
    float inch;
} distance ;

int main(void)
{
    distance d[2],sum;
    for(int i=0;i<2;i++)
    {
    printf("\nenter information for %d distance \n  ",(i+1));
    printf("enter feet : ");
    scanf("%d",&d[i].feet);
    printf("\n enter inch : ");
    scanf("%f",&d[i].inch);
    }
    sum.feet=d[1].feet +d[0].feet;
    sum.inch=d[1].inch +d[0].inch;
    if(sum.inch > 12)
    {
        sum.inch-=12.0;
        ++sum.feet;
    }
    printf("\n sum of distance =%d - %.2f ",sum.feet,sum.inch);
    return 0;
}