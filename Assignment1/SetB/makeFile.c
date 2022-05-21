//wap to  accepta and write that data in a file. Accept name and if of employee and write the name in file
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct employee_data
{
    int empid;
    int empAge;
    char ename[SIZE];
}employee;

// MAIN FUCNTION HERE 
int main(int argc, char const *argv[])
{
    int n , i;
    FILE *fp;
    employee emp;
    //open a file in write mode
    fp = fopen("employee.txt" , "w");
    if(NULL == fp){
        printf("\nError in  opening the file !!!!");
        exit(1);
    }

    //accept data from user
    printf("\n----WRITE DATA IN FILE -----\n");
    
    //accept numbers
    printf("\nEnter how many name you wanna write  : ");
    scanf("%d" , &n);

    //accept data from user and write data in file
    for(i=0;i<n;++i)
    {
        printf("\nEnter Employee %d Name: " , i+1);
        scanf("%s" , emp.ename);

        printf("\nEnter Employee %d ID : " , i+1);
        scanf("%d" , &emp.empid);

        printf("\nEnter Age of employee : ");
        scanf("%d" , &emp.empAge);
        //write data in file
        fprintf(fp , " %d %d %s ", emp.empAge , emp.empid , emp.ename);
    }
    fclose(fp);
    printf("\n-----THANK YOU USE AGAIN-----\n");
    return 0;
}
