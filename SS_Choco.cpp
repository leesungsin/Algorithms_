#include <iostream>

int main(void){

	int NR_e; // N값 입력
	int NR_l; // M값 입력
	int NR_L; // 결과값 저장

	std::cin>>NR_e>>NR_l;

	NR_L = (NR_e - 1) + (NR_l - 1) * NR_e;

	std::cout<<NR_L<<std::endl;
	return 0;
}