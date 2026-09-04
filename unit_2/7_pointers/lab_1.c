#include <stdio.h>
/*
user enter the boxes,
program calculate the sum and weight of 5 boxes
*/
#define BOXES_SIZE 5
int main()
{
    int boxes[BOXES_SIZE]={0};
    int * ptr = boxes;
    int sum=0;
    for(int iterator=0;iterator <BOXES_SIZE ;iterator++)
        {
            printf("\n enter box number %d :",iterator+1);
            scanf("%d",ptr+iterator);
        }

        for(int iterator=0;iterator <BOXES_SIZE ;iterator++)
        {
            sum+=*(ptr+iterator);
        }

    printf("sum= %d\n",sum);

    return 0;
}
