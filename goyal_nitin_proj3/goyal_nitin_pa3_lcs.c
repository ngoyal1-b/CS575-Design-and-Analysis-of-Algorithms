#include<stdio.h>
#include<string.h>


int main(int argc,char *argv[])
{
	//count for the number of arguments provided by user
	if(argc < 2)
	{
		printf("Please enter correct number of Strings\n");
		return 0;
	}
	//declaring string 
	char str1[100];
	strcpy(str1,argv[1]);
	char str2[100];
	strcpy(str2,argv[2]);
	
	int m = strlen(str1);//size of string1
	int n = strlen(str2);//size of string2
	
	int c[m+1][n+1];//for matrix
	char b[m+1][n+1];//for directions(U,D,L)
	/*intializing the first row and first column of matrix to 0*/
	c[0][0] = 0;
	for(int i = 1; i <= m; i++)
		c[i][0] = 0;
	for(int j = 1; j <= n; j++)
		c[0][j] = 0;
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1;j <= n; j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 'D';
			}
			else
			{
				if(c[i-1][j] >= c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					b[i][j] = 'U';
				}
				else
				{
					c[i][j] = c[i][j-1];
					b[i][j] = 'L';
				}
			}
		}
	}
	//printing longest common subsequence
	printf("\nLength of longest common subsequence is %d",c[m][n]);
	int index = c[m][n];
	int count = 0;
	char ans[index];//creating char array for storing string
	int i = m,j=n;
	while(i > 0 && j > 0)
	{
		if(b[i][j] == 'L')
			j--;
		else if(b[i][j] == 'D')//for every diagonal there is value of LCS
		{
			ans[index-1] = str1[i-1];
			index--;
			i--;
			j--;
		}
		else
			i--;

	}
	printf("\nLongest common subsequence is %s\n",ans);

}
	