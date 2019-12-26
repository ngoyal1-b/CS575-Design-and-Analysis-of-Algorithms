#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int n;
int path(int P[][n],int D[][n],int i,int j)
{
	if(P[i][j] != 0)
	{
		path(P,D,i,P[i][j]);
		printf("%d->",P[i][j]);
		path(P,D,P[i][j],j);
	}
}

int floyd_algo(int A[][n])
{
	int P[n][n];
	int D[n][n];
	//initializing distance and path matrix
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			D[i][j] = A[i][j];
			P[i][j] = 0;
		}
	}
	//Flyod's Algorithm

	for(int k = 1;k<=n;k++)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;
				}
			}
		}
	}
	printf("\nWeight  ShortestPath\n");
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(i!=j)
			{
				printf("%d ",D[i][j]);
				printf("\t%d->",i);
				if(P[i][j]!=0)
					path(P,D,i,j);
				printf("%d\n",j);
		}
		}
	}
}

int main()
{
	srand ( time(NULL) );
	// getting a value of n
	n = rand()%10 + 5;// creating rand() to get the value of n from 5 to 10 
	if(n>10)
		n = n - 4;
	printf("Selected n value is %d\n",n);
	// creating a adjacency matrix
	int A[n][n];
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(i == j)
				A[i][j] = 0;
			else
				A[i][j] = rand()%10 + 1;// rand() function to get the value between 1 and 10
			A[j][i] = A[i][j];
		}
	}
	//printing adjacency matrix
	printf("\nAdjacency matrix:\n");
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	floyd_algo(A);
}

