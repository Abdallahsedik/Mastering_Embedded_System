#include stdio.h
#include stdlib.h

/*
■ Q2
Write a program in C to print all the alphabets using a pointer. Go
to the editor
Expected Output 
The Alphabets are 
Expected Output 
A B C D E F G H I J K L M N O P Q
R S T U V W X Y Z
*/
#define Alphabets_size 26
int main()
{
    char Alphabets [Alphabets_size]={0};
    char  ptr = Alphabets;

    printf(n The Alphabets are  );
    for (int iterator =0 ; iterator  Alphabets_size ;iterator++ )
        {
            ptr=iterator+'A';
            printf(%c ,ptr);
            ptr++;
        }

    return 0;
}