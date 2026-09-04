#include <stdio.h>
#include <stdlib.h>
/*
make a function to dumb any address in memory with specific size
*/
void print_memory_range(char * base ,int size );

typedef struct{
char data1;
int  data2;
char data3;
short data4;
}data;
int main()
{
    data new_data= {0};
    new_data.data1=0x11;
    new_data.data2=0xFFFFEEEE;
    new_data.data3=0x22;
    new_data.data4=0xABCD;
    print_memory_range((char *)&new_data,sizeof(new_data));

    return 0;
}


void print_memory_range(char * base ,int size )
{
for(int i=0;i<size ; i++)
    {
    printf("%p \t %x \n",base ,(unsigned char )*base );
    base++;

    }
}
