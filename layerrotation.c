#include<stdio.h>

void get_ac_shift(int **A, int m, int n, int l)
{
	// store all the corner elements of the ith layer
	int i=l;
	int topleft=A[i-1][i-1], topright=A[i-1][n-i];
	int bottomleft=A[m-i][i-1], bottomright=A[m-i][n-i];
	
	for (i=l-1;i<n-l;i++)//this loop is to access the l-1th row from the l-1 col to m-l col
	{
		A[l-1][i]=A[l-1][i+1];
	}
	for(i=m-l;i>l-1;i--)//this loop is to access the l-1th col from the m-lth row to l-1th row
	{
		A[i][l-1]=A[i-1][l-1];
	}
	for(i=n-l;i>l-1;i--)// this loop is to access the m-lth row from the m-l col to l-1 col
	{
		A[m-l][i]=A[m-l][i-1];
	}
	for(i=l-1;i<m-l;i++) //this loop is to access the n-lth col from l-1th row to m-lth row
	{
		A[i][n-l]=A[i+1][n-l];
	}
	A[l][l-1]=topleft;
	A[m-l][l]=bottomleft;
	A[m-l-1][n-l]=bottomright;
	A[l-1][n-l-1]=topright;	
}

void get_c_shift(int **A, int m, int n, int l)
{
	// store all the corner elements of the ith layer
	int i=l;
	int topleft=A[i-1][i-1], topright=A[i-1][n-i];
	int bottomleft=A[m-i][i-1], bottomright=A[m-i][n-i];
	
	for (i=n-l;i>l-1;i--)//this loop is to access the l-1th row from the n-l col to l-1 col
	{
		A[l-1][i]=A[l-1][i-1];
	}
	for(i=l-1;i<m-l;i++)//this loop is to access the l-1th col from the l-1th row to m-lth row
	{
		A[i][l-1]=A[i+1][l-1];
	}
	for(i=l-1;i<n-l-1;i++)// this loop is to access the m-lth row from the n-l col to l-1 col
	{
		A[m-l][i]=A[m-l][i+1];
	}
	for(i=m-l;i>l-1;i--) //this loop is to access the n-lth col from l-1th row to m-lth row
	{
		A[i][n-l]=A[i-1][n-l];
	}
	A[l-1][l]=topleft;
	A[m-l-1][l-1]=bottomleft;
	A[m-l][n-l-1]=bottomright;
	A[l][n-l]=topright;	
}

int main()
{
	//get the size of the array;
	int m,n;
	scanf("%d %d ",&m,&n);
	//get array elements
	int i,j;
	int **A = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        A[i] = (int *)malloc(n * sizeof(int));
    }
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %d ",&A[i][j]);
		}
	}
	//Get final row;
	printf("\nGetting final inputs: \n");
	char c; int shift,layer;
	scanf(" %c %d %d ",&c,&shift,&layer);
	//All inputs are done
	
	if(c =='A')
	{
		printf("Shifting going on \n");
		for(i=0;i<shift;i++)
		{
			get_ac_shift(A,m,n,layer);
		}
	}
	else if(c == 'C')
	{
		for(i=0;i<shift;i++)
		{
			get_c_shift(A,m,n,layer);
		}
	}
	//We are done with our operation now just print the Array A now
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",A[i][j]);	
		}	
		printf("\n");
	}	
	
	for (i = 0; i < m; i++)
    {
        free(A[i]);
    }
    free(A);

	return 0;
}
