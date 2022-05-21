#include<stdio.h>
#define MAT_SIZE 10

#define SIZE 3

int main()
{
	int sparseMatrix[MAT_SIZE][MAT_SIZE] , i , j , r, c,size=0 , k=0;

	//take innput from user
	printf("\nEnter size of the matrix : [MAX : 10*10]");
	scanf("%d %d",&r , &c);

	if(r>10 || c>10)
	{
		printf("\nGiven size is bigger then MAX size !!!\n");
		return 1;
	}

	printf("\nEnter %d elements for SparseMatrix : ",r*c);

	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			scanf("%d",&sparseMatrix[i][j]);
			if(sparseMatrix[i][j] != 0)
			{
				size++;
			}
		}
	}

	printf("\nSize : %d \n",size);
	//get the compact  matrix
	int c_matrix[SIZE][size];

	for(i=0;i<SIZE;++i)
	{
		for(j=0;j<size;++j)
		{
			if(sparseMatrix[i][j] != 0)			//check if the element is zero or non zero
			{
				c_matrix[0][k] = i;
				c_matrix[1][k] = j;
				c_matrix[2][k] = sparseMatrix[i][j];
				k++;
			}

			printf("\t%d",sparseMatrix[i][j]);
		}
		printf("\n");
	}


	printf("\nCompact Matrix is: \n");
	for(i=0;i<3;++i)
	{
		for(j=0;j<size;++j)
		{
			printf("\t%d",c_matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

