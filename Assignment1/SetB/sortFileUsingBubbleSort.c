//wap to sort a given file , with the help of bubble sort

#include<stdio.h>
#include <string.h>
#define SIZE 10

// STRUCTURE HERE 
typedef struct sortFileUsingBubbleSort
{
    int empId;
    char empName[SIZE];
    int empAge;
}employee;


// MAIN FUNCTION HERE
int main(int argc, char const *argv[])
{
    FILE *fp;
    int i ,j ,n = 0 , flag=0;
    employee emp[SIZE] ,temp;
    
    //read the file from another files
    fp = fopen("employee.txt" , "r");
    if(NULL == fp){
        perror("\nEnable to open file !!!.....");
        return 1;
    }
    printf("\n-----SORT THE FILE BY USER NAME --------\n");

    printf("\nReading File !!!\n");

    while(!feof(fp))
    {     //read the file till pointer is at eof
            fscanf(fp , "%d %d %s" ,&emp[i].empAge ,&emp[i].empId , emp[i].empName); 
            i++;
    }
    n = i-1;        //this is just for my file dont do it as i-1;
    printf("\nReading Complete!!!\n");
    
    //sort the file
    printf("\nSorting the File \n");
    for(i=0;i<n;++i)
    {
        for(j=0;j<n-1-i;++j)
        {
            if((strcmp(emp[j].empName , emp[j+1].empName))>0)
            {       
                    flag = 1;
                    temp = emp[j];  
                    emp[j] = emp[j+1];
                    emp[j+1] = temp;
            }
        }
        if(flag == 0){
            break;
        }
    }

    printf("\nThe Sorted Names are  : \n");
    for(i=0;i<n;++i){
        printf("\n[%d] %d %d %s" , i+1 , emp[i].empId , emp[i].empAge , emp[i].empName);
    }

    fclose(fp);
    //write the data in file
    fp = fopen("employeeSortByName.txt" , "w");
    if(NULL == fp){
        perror("\nErrror  In opening File  ..........:");
        return 1;
    }

    for(i=0;i<n;++i)
    {
        fprintf(fp , "%d %d %s " , emp[i].empId , emp[i].empAge , emp[i].empName);
    }
    printf("\nWrriten Done successfully!!!!\n");
    fclose(fp);
    return 0;
}
