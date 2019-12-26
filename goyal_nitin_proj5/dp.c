#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
int capacity;
int selected[10][100];
int B[10][100];
int refinement(int size,int c,int weight[],int profit[])
{
	if(size == 0 || c <= 0)
		return 0;
	else
	{
		for(int i = size-1;i>=0;i--)
		{
			if(weight[i]>c)
			{	
				selected[size][c] = 0;
				return refinement(size-1,c,weight,profit);
			}
			else
			{
				int tmp1 = refinement(size-1,c,weight,profit);
				int tmp2 = profit[i] + refinement(size-1,c-weight[i],weight,profit);
				if(tmp1 > tmp2)
				{
					selected[size][c] = 0;
					B[size][c] = tmp1;
					return tmp1;
				}
				else
				{
					selected[size][c] = 1;
					B[size][c] = tmp2;
					return tmp2;
				}
			}
		}
	}
		return 0;
}


int main(int argc,char*argv[])
{
	if(argc != 2)
	{
		printf("Error: please provide the file name\n");
		return 0;
	}
	//int n,capacity;
	FILE *fp = fopen("output2.txt","w");
	FILE *fp1 = fopen(argv[1],"r");
	FILE *fp2 = fopen("entries2.txt","w");
	int totalProfit = 0,totalWeight = 0;
	int count = 0;
	int p,w,j;
	char c[10];
	fscanf(fp1,"%d %d",&n,&capacity);
	int sum = 0;
	int profit[n];
	int weight[n];
	int i = 0;
	while(!feof(fp1) && i<n)
	{
		fscanf(fp1,"%s %d %d %d",&c,&j,&p,&w);
		profit[i] = p;
		weight[i] = w;
		i++;
	}

	totalProfit = refinement(n,capacity,weight,profit);
	int temp1 = n,temp2 = capacity;
	for(int i = 0;i<n;i++)
	{
		if(selected[temp1][temp2] == 1)
		{
			count++;
			totalWeight = totalWeight + weight[temp1-1];
			temp2 = temp2 - weight[temp1-1];
		}
		temp1--;
	}
	fprintf(fp,"%d %d %d\n",count,totalProfit,totalWeight);
	int size,W;
	size = n;W = capacity;
	for(int i = 1;i<=n;i++)
	{
		if(selected[size][W] == 1)
		{	
 			fprintf(fp," %d %d\n",profit[size-1],weight[size-1]);
 			W = W - weight[size-1];
		}
		size--;
	}
	for(int i = 1;i<=n;i++)
	{
		fprintf(fp2,"row%d ",i);
		for(j = 0;j<=capacity;j++)
		{
			if(B[i][j] != 0)
			{
				fprintf(fp2,"  %d ",B[i][j]);
			}
		}
		fprintf(fp2,"\n");
	}

}