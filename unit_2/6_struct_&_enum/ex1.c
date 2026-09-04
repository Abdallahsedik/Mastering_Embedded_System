#include <stdio.h>
/*
c program to store information (name ,roll and marks) of  students
 using struct 
*/
#define ARRAY_SIZE  5
#define NAME_SIZE   20
typedef struct 
{
    char  name [NAME_SIZE];
    int   roll;
    float marks;
}Student;

int main(void)
{
    
    Student students[ARRAY_SIZE];
    int number=0;
    printf("enter number of students \'less than 5\' : ");
    scanf("%d",&number);
   //validation check
    if (number > ARRAY_SIZE) {
    number = ARRAY_SIZE;  
    }

    for (int i = 0; i < number; i++)
    {
        printf("\n enter student %d name  : ",(i+1));
        scanf("%s", students[i].name); 
        printf("\n enter student %d roll  : ",(i+1));
        scanf("%d", &students[i].roll);
        printf("\n enter student %d marks  : ",(i+1));      
        scanf("%f", &students[i].marks);    
        printf("\n---------------------------\n");
    }

    for (int i = 0; i < number; i++)
    {
        printf("Name: %s, Roll: %d, Marks: %.2f\n", 
           students[i].name, students[i].roll, students[i].marks);
    }
}