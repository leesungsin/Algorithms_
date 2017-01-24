#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


int main(void){

	int peopleNumber=0; // 사람수 
	std::cin>>peopleNumber;
	int *saveTime = new int[peopleNumber]; // int 타입 동적 메모리 할당


	// 동적할당 한 1차원 배열인 saveTime에 값 입력
	for(int index=0; index<peopleNumber; index++) {
		std::cin>>saveTime[index];
	}

	// 오름차순 정렬
	for(int outIndex = 0; outIndex < peopleNumber-1; outIndex++){
		for(int inIndex = outIndex+1 ; inIndex < peopleNumber; inIndex++){
			if(saveTime[inIndex] < saveTime[outIndex] ){
				int temp = saveTime[outIndex];
				saveTime[outIndex] = saveTime[inIndex];
				saveTime[inIndex] = temp;
			}// end if
		}// end for inIndex
	}// end for outIndex

	for(int i=0; i<peopleNumber; i++)
		std::cout<<"sort reusult : "<<saveTime[i]<<std::endl;

	int sum = 0 ;
	// 부분합 구하기
	for(int outIndex =0; outIndex < peopleNumber; outIndex++){
		for(int inIndex = 0 ; inIndex <= outIndex; inIndex++){
				sum = sum + saveTime[inIndex];
		}
	}

	std::cout<<"sum result : "<<sum<<std::endl;

	// STL vector 를 사용하여 위와 동일한 소스코드 작성
	std::vector<int> saveTime_vector;
	int peopleNumber_vector=0;
	int saveTime_;
	std::vector<int> saveTime_patial_vector;
	int saveTime_sum_vector;

	std::cin>>peopleNumber_vector;

	for(int index_vector = 0 ; index_vector < peopleNumber_vector ; index_vector ++){
		std::cin>>saveTime_;
		saveTime_vector.push_back(saveTime_);
	}

	sort(saveTime_vector.begin(), saveTime_vector.end());

	for(int j=0; j<peopleNumber_vector ; j++){
		std::cout<<"sort result : "<<saveTime_vector.at(j)<<std::endl;
	}

	std::partial_sum(saveTime_vector.begin(), saveTime_vector.end(), std::back_inserter(saveTime_patial_vector));
	saveTime_sum_vector = std::accumulate(saveTime_patial_vector.begin(), saveTime_patial_vector.end(), 0);
	std::cout<<"result : "<<saveTime_sum_vector<<std::endl;

	


	return 0;
}