#include<stdio.h>
using namespace std;

int main()
{
	int i; 
	int k,j; 
	printf("Enter The Row of Pyramid: ");
	scanf("%i",&i);	
	
	for(k=0;k<i;k++)
	{
		for(j=0;j<k+1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
