#include <stdio.h>
#include <stdlib.h>

int main(){
	int M = 0;
	int N = 0;

	scanf_s("%d", &M);
	scanf_s("%d", &N);

//	int *C = (int*)malloc(sizeof(int)*(M*N));
//	*C = M*N - 1;
//	printf("%d\n", *C);

	int Choco = M*N - 1;
	printf("%d\n", Choco);

	return 0;
}