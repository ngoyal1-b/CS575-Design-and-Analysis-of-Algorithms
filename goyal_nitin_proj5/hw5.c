#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int n,capacity;
int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("Error: please provide the file name\n");
		return 0;
	}
	FILE *fp=fopen(argv[1],"w");
	srand(time(NULL));
	//getting random value of n between 4 and 8
	n = rand()%10 + 4;
	if(n>8)
		n = n - 5;
	int profit[n],weight[n];
	int sum = 0;
	for(int i = 1;i<=n;i++)
	{
	//getting random value of profit array between 10 and 30
	profit[i] = rand()%30 + 10;
	if(profit[i]>30)
		profit[i] = profit[i] - 9;
	//getting random value of weight array between 5 and 20
	weight[i] = rand()%20 + 5;
	if(weight[i]>20)
		weight[i] = weight[i] - 4;
	sum = sum + weight[i];
	}
	//getting capacity of knapsack
	capacity = floor(0.6*sum);

	fprintf(fp,"%d    %d\n",n,capacity);
	for(int i = 1;i<=n;i++)
	{
		fprintf(fp,"Item %d    %d    %d",i,profit[i],weight[i]);
		fprintf(fp,"\n");
	}


}