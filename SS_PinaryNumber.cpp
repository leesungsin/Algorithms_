#include <iostream>

// std::cout, std::cin 에서 std::를 안쓰고 싶다면 ? 
// header file 아래, 혹은 main 함수 실행 전 
// using namespace std; 를 선언하면 됨. (비추)


int fibonacci(int NR_F);

int	main(void)
{

	int  NR_I  = 0 ;   // 이친수의 갯수 입력 변수
	int  NR_E  = 0 ;   // 이친수(피보나치수열) 갯수 저장 변수
	bool NR_G  = true; // 입력값이 1~90 범위를 넘어서면, 다시 입력받을수 있게 while을 실행시키기 위한 변수  
	int  NR_T  = 0 ;   // 피보나치 수열값 저장.
	
	while(NR_G){
		std::cin >> NR_I;
		if(NR_I >=1 && NR_I <=90){
			NR_G = false;
		}
		else{
			std::cout<<"1 ~ 90 사이의 숫자를 입력해주세염 : ";
		}
	} // end while

	
	NR_T = fibonacci(NR_I);
	std::cout<<"NR_T (이친수 갯수) : " << NR_T << std::endl;

	return 0;
}

int fibonacci(int NR_F)
{
	if(NR_F <=1)
	{
		return NR_F;
	}
	else
	{
		return fibonacci(NR_F-1) + fibonacci(NR_F-2);
	}
}