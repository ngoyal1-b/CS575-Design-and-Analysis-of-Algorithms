#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,capacity;
int count = 0;
int tempweight = 0;
int tempprofit = 0;
int maxprofit,num;
float temp;
int best[10];
int X[10];
FILE *fp;
FILE *fp2;
int include[10];
int KWF2(int i,int w,int p,int size,int c,int weight[],int profit[])
{
	int bound = p;
	while(w<c && i<=size)
	{
		if(w + weight[i-1] <= c)
		{
			w = w + weight[i-1];
			bound = bound + profit[i-1];
		}
		else
		{
			temp = (float)(c-w)/(float)weight[i-1];
			w = c;
			bound = bound + profit[i-1]*temp;
		}
		i++;
	}
	return bound;
}
int promising(int i,int p,int c,int w,int size,int weight[],int profit[])
{
	if(w >= c)
		return 0;
	int bound = KWF2(i+1,w,p,size,c,weight,profit);
	fprintf(fp2,"%d %d %d\n",p,w,bound);
	return (bound > maxprofit);
}

void knapsack(int i,int p,int w,int c,int size,int weight[],int profit[])
{
	if(w <= c && p > maxprofit)
	{
		maxprofit = p;
		num = i;
		for(int j = 1;j<=n;j++)
			best[j] = include[j];
	}
	if(promising(i,p,c,w,size,weight,profit))
	{
		include[i+1] = 1;
		knapsack(i+1,p+profit[i],w+weight[i],c,size,weight,profit);
		include[i+1] = 0;
		knapsack(i+1,p,w,c,size,weight,profit);
	}
}
void backtrack(int weight[],int profit[])
{
	num = 0;
	maxprofit = 0;
	knapsack(0,0,0,capacity,n,weight,profit);
	for(int i = 1;i<=n;i++)
	{
		if(best[i] == 1)
		{
			count++;
			tempprofit = tempprofit + profit[i-1];
			tempweight = tempweight + weight[i-1];
		}
	}
	fprintf(fp,"%d %d %d\n",count,tempprofit,tempweight);
	for(int i = 1;i<=n;i++)
	{
		if(best[i] == 1)
		{
			fprintf(fp,"item%d %d %d\n",i+1,profit[i-1],weight[i-1]);
		}
	}

}

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("Error: please provide the file name\n");
		return 0;
	}
	fp = fopen("output3.txt","w");
	FILE *fp1 = fopen(argv[1],"r");
	fp2 = fopen("entries3.txt","w");
	int totalProfit = 0,totalWeight = 0;
	int count = 0;
	int p,w,j;
	char c[10];
	fscanf(fp1,"%d %d",&n,&capacity);
	int sum = 0;
	int profit[n];
	float ppw[n];//profit per unit weight
	int weight[n];
	int i = 0;
	while(!feof(fp1) && i<n)
	{
		fscanf(fp1,"%s %d %d %d",&c,&j,&p,&w);
		profit[i] = p;
		weight[i] = w;
		i++;
	}
	int temp1,temp2,temp3;
	for(int i = 0;i<n;i++)
	{
		ppw[i] = ((float)profit[i]/(float)weight[i]);
		
	}
	for(int i = 0;i<n-1;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(ppw[i] < ppw[j])
			{
				temp3 = ppw[i];
				ppw[i] = ppw[j];
				ppw[j] = temp3;
				temp2 = profit[i];
				profit[i] = profit[j];
				profit[j] = temp2;
				temp1 = weight[i];
				weight[i] = weight[j];
				weight[j] = temp1;
			}
		}
	}
	backtrack(weight,profit);
}