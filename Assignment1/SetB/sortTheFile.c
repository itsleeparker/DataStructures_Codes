//wap to accept data from the file , and sort this data based on emplyee name using insertion algorithim

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct employee_data
{
    int empId;
    int empAge;
    char ename[SIZE];
}employee;


// MAIN  FUNCITON HERE 
int main(int argc, char const *argv[])
{
    int n=0 , i=0 , j , flag=0;
    FILE *fp;
    employee emp[SIZE] , temp;
    fp = fopen("employee.txt" , "r");
    if(fp == NULL)
    {
        perror("Error in opeing file .....: ");
        exit(1);
    }

    //check for data in file and start sorting it by age 
    printf("\nSorting data !!!");
    while(!feof(fp))
    {
        fscanf(fp , "%d %d %s " ,&emp[i].empAge ,&emp[i].empId ,emp[i].ename);
        //display data to check 
        printf("\n%d %s is %d years old \n" , emp[i].empId , emp[i].ename , emp[i].empAge);
        i++;
    }
    fclose(fp);
    n=i;

    printf("\nSorted Data is  : \n");
    //SORT THE DATA BY AGE 
    for(i=1 ;i<n;++i)
    {
       
        j = i-1;
        temp = emp[i];
        while( j>=0 && emp[i].empAge >= temp.empAge){            
            emp[j+1] = emp[j];
            j--;
        }
        emp[j+1] = temp;
    }

    for(i=0;i<n;++i){
        printf("\n%d %s %d\n" , emp[i].empId , emp[i].ename , emp[i].empAge);
    }

    fp = fopen("sortedEmployee.txt" ,"w");
    if(NULL ==  fp){
        perror("Error while opening file !!!.....");
        exit(1);
    }

    //write data in file
    for(i=0;i<n;++i){
        fprintf(fp , " %d %s %d " , emp[i].empId  , emp[i].ename , emp[i].empAge);
    }
    return 0;
}