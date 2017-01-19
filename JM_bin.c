#include <stdio.h>

long long NumOfPinary(int n);

int main(){
	int n;
	scanf("%d",&n);
	printf("%lld",NumOfPinary(n));

	return 0;
}

/*
long long NumOfPinary(int n){
	if (n == 1 || n==2)
		return 1;
	else
		return (NumOfPinary(n-1)+NumOfPinary(n-2));
}
*/


long long NumOfPinary(int n){
	long long sum = 1, pre = 0, tmp;

	for(int i=1;i<n;i++){
		tmp = sum;
		sum += pre;
		pre = tmp;
	}
	return sum;
}

