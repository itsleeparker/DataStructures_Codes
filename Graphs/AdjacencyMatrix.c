//wap to implment adjacency matrix and count indegree and outdegree of each vertex 
#include<stdio.h>
#define SIZE 10

void AcceptMat(int mat[SIZE][SIZE] ,int n)
{
    int i , j;
    char op;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("\nIs there a vertex between %d and  %d [y/n] : " , i ,j);            
            scanf(" %c" , &op);
            if(op == 'y'  || op == 'Y'){
                mat[i][j] = 1;
            }
            else{
                mat[i][j] = 0;
            }
        }
    }
}

void Display(int mat[SIZE][SIZE] ,int n){
    int i , j;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            printf("%3d" , mat[i][j]);

        }
        printf("\n");
    }

}

//count the indegree and outdegree of each vertex 
void DisplayDegree(int mat[SIZE][SIZE] , int n){
    int indegree = 0 , outdegree = 0 , i  , j;
    for(i=0;i<n;++i){
        indegree = 0;
        for(j=0;j<n;++j){
            if(mat[j][ i]!=0){
                    indegree++;
            }
        }
        outdegree=  0;
        for(j=0;j<n;++j){
            if(mat[i][j]!=0){
                outdegree++;
            }
        }
        printf("\nThe degree for Edge %d %d is  in[%d] out[%d]" ,i , j , indegree ,outdegree);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int matrix[SIZE][SIZE];         //create the matrix to accept vertices 
    int n;
    printf("\n--ADJACENT MATRIX----\n");
    printf("\nEnter how many vertices you need : ");
    scanf("%d" , &n);
    AcceptMat(matrix ,n);
    Display(matrix , n);
    DisplayDegree(matrix , n);
    return 0;
}