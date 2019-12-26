#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int selected[10];
int n,capacity;
int bestValue,bestWeight;
int burteforce(int weight[],int profit[])
{
	int A[n];
	int count = 0;
	int k,bestValue = 0,bestWeight = 0;
	memset(A, 0, sizeof(A)); 
	for(int i = 0;i<pow(2,n);i++)
	{
		int isSelected = 1;
		int tempValue = 0;
		int tempWeight = 0;
		for(k = 0;k<n;k++)
		{
			if(A[k] == 1)
			{
				tempWeight = tempWeight + weight[k];
				tempValue = tempValue + profit[k];
			}
		}

		if((tempValue > bestValue) && (tempWeight <= capacity))
		{
			for(int j = 0;j<n;j++)
			{
				selected[j] = A[j];
			}
			bestValue = tempValue;
		}
		for(int j =0;j<n;j++)
		{
			A[j] = A[j] + isSelected;
			isSelected = A[j]/2;
			A[j] = A[j]%2;
		}

	}
	return bestValue;

}

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("Error: please provide the file name\n");
		return 0;
	}
	FILE *fp = fopen("output1.txt","w");
	FILE *fp1 = fopen(argv[1],"r");
	int totalProfit = 0,totalWeight = 0;
	int count = 0;
	int p,w,j;
	char c[10];
	fscanf(fp1,"%d %d",&n,&capacity);
	int sum = 0;
	int profit[n],weight[n];
	int i = 0;
	while(!feof(fp1) && i<n)
	{
		fscanf(fp1,"%s %d %d %d",&c,&j,&p,&w);
		profit[i] = p;
		weight[i] = w;
		i++;
	}

	for(int i = 0;i<n;i++)
	{
	sum = sum + weight[i];
	}
	totalProfit = burteforce(weight,profit);

	for(int i = 0;i<n;i++)
	{
		if(selected[i] == 1)
		{
			count++;
			totalWeight = totalWeight + weight[i];
		}
	}
	fprintf(fp,"%d %d %d\n",count,totalProfit,totalWeight );
	for(int i = 0;i<n;i++)
	{
		if(selected[i] == 1)
			fprintf(fp,"item%d %d %d\n",i+1,profit[i],weight[i]);
	}
}




