#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define INF 999

int n;
int Set[11];
int find3(int x)
{
	//find root of tree with x
	int root = x;
	while(root != Set[root])
		root = Set[root];
	int node = x,parent;
	while(node != root)
	{
		parent = Set[node];
		Set[node] = root;// node points to root
		node = parent;
	}
	return root;
}

void union3(int i,int j)
{
	/*int *height;
	height = calloc(n,sizeof(int));
	for(int i = 0;i<n;i++)
		height[i] = -1;
	if(height[repx] == height[repy]){
		height[repx]++;
	Set[repy] = repx;}
	else{
		if(height[repx] > height[repy])
			Set[repy] = repx;
		else
	Set[repx] = repy;}*/
	int repx = find3(i);
	int repy = find3(j);
	Set[repx] = repy;
}

int prim(int A[][n])
{
	printf("\n\nMINIMUM SPANNING TREE USING PRIM ALGORITHM\n\n");
	int edge;
	int x,y;
	int selected[11] = {0};
	edge = 0;
	selected[1] = 1;
	while(edge < n-1)
	{
		int min = INF;
		x = 1;
		y = 1;
		for(int u = 1;u<=n;u++)
			if(selected[u])
				for(int v = 1;v<=n;v++)
				{
					if(!selected[v] && A[u][v])
						if(min > A[u][v])
						{
							min = A[u][v];
							x = u;
							y = v;
						}
				}
		printf("%d - %d\n",x,y);
		selected[y] = 1;
		edge++;
	}
}
int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 

int kruskal(int A[][n])
{  
	printf("\n\nMINIMUM SPANNING TREE USING KRUSKAL ALGORITHM\n\n");
    // Initialize sets of disjoint sets. 
    for (int i = 1; i <= n; i++) 
        Set[i] = i;
    // Include minimum weight edges one by one 
    int edge = 0; 
	
	qsort(A, n, sizeof(int), compare); 

    int ucomp,vcomp;
    while (edge < n - 1) { 
        int min = INF, a = 0, b = 0;
        for (int u = 1; u <= n; u++) 
        { 
            for (int v = 1; v <= n; v++) 
            { 
            	ucomp = find3(u);
            	vcomp = find3(v);
                if (ucomp != vcomp && A[u][v] < min)
                 { 
                    min = A[u][v]; 
                    a = u; 
                    b = v; 
                } 
            } 
        } 
        union3(a,b); 
        printf("%d - %d\n", a, b); 
        edge++;
    } 
}

int main()
{
	srand ( time(NULL) );
	//getting a value of n
	n = rand()%10 + 5; // creating rand() to get the value of n from 5 to 10
	if(n>10)
		n = n - 4;
	//n = 4;
	printf("Selected n value is %d\n",n);
	//creating an adjacency matrix
	int A[n][n];
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(i == j && j == i){
				A[i][j] = 0;
			}
			else
				A[i][j] = rand()%10 + 1;// rand() function to get the value between 1 and 10
			A[j][i] = A[i][j];
		}
	}
	// printing adjacency matrix
	printf("\n Adjacency matrix:\n");
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}

	int choice;
	do{
	printf("\nPlease select the minimum spanning tree algorithm you want to apply:\n");
	printf("1. Prim's algorithm\n");
	printf("2. Kruskal's algorithm\n");
	printf("0. EXIT\n");
	scanf("%d",&choice);
	if(choice == 1)
		prim(A);
	else if(choice == 2)
		kruskal(A);
	else if(choice ==0)
		break;
	else 
		printf("Error : Algorithm u selected is not available to execute\n");
	
	}while(choice != 0);
}


