#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	long long sum = 0;


	scanf("%d",&N);
	int *P = (int*)malloc(sizeof(int)*N);

	for(int i=0;i<N;i++)
	{
		scanf("%d",(P+i)); 
	}

	int tmp = 0;
	for(int i=0; i<N-1;i++)
	{
		for(int j=i+1; j<N;j++)
		{
			if(*(P+j) < *(P+i))
			{
				tmp = *(P+i);
				*(P+i) = *(P+j);
				*(P+j) = tmp;
			}

		}
	}
	/*
	for(int i = 0; i<N; i++)
	{
		//sum += (N-i) * (*(P+i));
		printf("%d",*(P+i));
	}
	*/

	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<=i;j++)
		{
			sum += *(P+j);
		}
	}
	
	free(P);
	printf("%lld",sum);
	printf("\n");

	return 0;

}
