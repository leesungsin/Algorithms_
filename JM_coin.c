#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n=0,k=0;
	int quotient=0;

	scanf("%d %d",&n,&k);

	int *coin = (int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",(coin+i));
	}

	for(int i=n-1;i>=0;i--){
		quotient += k/(*(coin+i));
		k %= (*(coin+i));
	}

	printf("%d",quotient);

	free(coin)
	
	return 0;
}
