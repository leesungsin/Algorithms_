#include <iostream>


class Map{

private:
	// 맴버변수 선언
	// 접근연산자가 private 이기 때문에 외부에서 접근 불가능
	// 따라서 class 내부에서 맴버변수를 접근할 수 있는 getter 를 만들어줘야함.
	// 이를 수정하고 싶을 경우 satter 를 선언해서 수정해주면 됨.


	int NR_iSize;
	int ** NR_nForestMap;        // n*n 크기의 대나무 숲을 표현할 2차원 배열 포인터 선언
	int ** NR_lLiveDaysMap;      // 최대로 살수있는 날을 저장하는 2차원 배열 포인터 선언
	int NR_oMaxLiveDays;         // 최대로 살수있는 날을 저장 하기위한 변수
	static int NR_moveRow[4];			 // 상하좌우 움직일때 변화하는 행 값, C++ 에서 클래스내 배열을 초기화 할땐 static 키워드를 붙힘. 
	static int NR_moveCol[4]; 			 // 상화좌우 움직일때 변화하는 열 값

public:

	//default constructor
	Map(){
		NR_iSize        = 0;
		NR_nForestMap   = NULL;
		NR_lLiveDaysMap = NULL;
		NR_oMaxLiveDays = 0;
	}


	// 생성자 오버로딩(파라미터 값을 지정해줄 수 있음), 맴버변수 초기화
	// 입력받은 수만큼 2차원 배열 생성
	Map(int size){

		// 열 설정
		NR_nForestMap = new int*[size];
		NR_lLiveDaysMap = new int*[size];

		// 행 설정
		for(int i = 0 ; i<size ; i++ ){
			NR_nForestMap[i] = new int[size];
			NR_lLiveDaysMap[i] = new int[size];
		}// end for
		NR_oMaxLiveDays = 0 ; 
		NR_iSize = size;
	}
	

	// 소멸자
	// 생성자에서 메모리 할당한 부분을 해제함.
	~Map(){
		for (int i=0; i<NR_iSize; i++){
			delete [] NR_nForestMap[i];
			delete [] NR_lLiveDaysMap[i];
		}
		delete [] NR_nForestMap;
		delete [] NR_lLiveDaysMap;
	}

	// 맴버함수 선언
	void set_nForestMap();   // n*n 대나무숲 만들기
	void get_nForestMap();   // n*n 대나무숲이 잘 만들어졌는지 출력 , 단순 확인용
	void get_lLiveDaysMap();
	int move(int row, int col); 			 		  // 대나무 숲에서 이동
	int max(int NR_lLiveDaysMapValue, int maxValue); // 가장 오래 살 수 있는 날을 찾아서 NR_oMaxLiveDays에 저장.
	int get_oMaxLiveDays(); // 가장 오래 살 수 있는 날을 리턴해주는 getter 
	void set_oMaxLiveDays(int maxLiveDays);

};// end class Map

int Map::NR_moveRow[4]={-1,1,0,0}; // 상,하,좌,우
int Map::NR_moveCol[4]={0,0,-1,1}; // 상,하,좌,우 움직일때 변하는 값을 미리 저장


void Map::set_nForestMap(){
	// 데이터를 입력 & 저장
	// NR_voutIndex 는 바깥쪽 for문 시작변수 
	// NR_einIndex  는 안쪽 for문 시작변수
	for(int NR_voutIndex=0; NR_voutIndex < NR_iSize; NR_voutIndex ++){
		for(int NR_einIndex=0; NR_einIndex < NR_iSize; NR_einIndex ++){
			std::cin >> NR_nForestMap[NR_voutIndex][NR_einIndex];  // 데이터 저장
			NR_lLiveDaysMap[NR_voutIndex][NR_einIndex]=0; // 최대로 살 수 있는 날을 저장하는 배열을 0으로 초기화
		}// 안쪽 포문 {} 종료
	}// 바깥쪽 포문{} 종료
}

void Map::get_nForestMap(){

	//std::cout<<"======================="<<std::endl;
	for(int NR_voutIndex=0; NR_voutIndex < NR_iSize; NR_voutIndex ++){
		for(int NR_einIndex=0; NR_einIndex < NR_iSize; NR_einIndex ++){
			//std::cout<<NR_nForestMap[NR_voutIndex][NR_einIndex]<<" ";
		}// 안쪽 포문 {} 종료
		//std::cout<<std::endl;
	}// 바깥쪽 포문{} 종료
}

void Map::get_lLiveDaysMap(){
	//std::cout<<"======================="<<std::endl;
	for(int NR_voutIndex=0; NR_voutIndex < NR_iSize; NR_voutIndex ++){
		for(int NR_einIndex=0; NR_einIndex < NR_iSize; NR_einIndex ++){
			//std::cout<<NR_lLiveDaysMap[NR_voutIndex][NR_einIndex]<<" ";
		}// 안쪽 포문 {} 종료
		//std::cout<<std::endl;
	}// 바깥쪽 포문{} 종료
}

int Map::move(int row, int col){

	//std::cout<<"row , col " << row <<" " << col <<std::endl;
	if(0 == NR_lLiveDaysMap[row][col]){
		NR_lLiveDaysMap[row][col] = 1; // 처음위치에서는 살 수 있는 하루를 인정

		// NR_index < 4인 이유는 한 점에서 움직일수 있는 방향이 최대 4군대(동,서,남,북) 이기 때문.
		// 물론 나는 상, 하, 좌, 우 로 움직일 거지만 
		for(int NR_index=0; NR_index < 4; NR_index++){
			int NR_newRow = NR_moveRow[NR_index] + row ;
			int NR_newCol = NR_moveCol[NR_index] + col ;

			// n*n map 의 크기를 벗어나면 안되니 체크
			// 인덱스의 번호가 가장 작은 범위보다 작거나, 가장 큰 범위보다 클경우
			if(NR_newRow < 0 || NR_newCol < 0 || NR_newRow >= NR_iSize || NR_newCol >= NR_iSize)
				continue;
			// 문제 조건 , 처음위치 < 나중위치 일때만 움직임
			if(NR_nForestMap[row][col] >= NR_nForestMap[NR_newRow][NR_newCol])
				continue;

			//위의 두조건을 만족시킬경우 움직임!!
			NR_lLiveDaysMap[row][col] = max(NR_lLiveDaysMap[row][col], move(NR_newRow, NR_newCol)+1);

			//std::cout<<std::endl;
		}// end for int NR_index
	}// end if


//	std::cout<<"NR_lLiveDaysMap["<<row<<"]["<<col<<"] : "<<NR_lLiveDaysMap[row][col]<<std::endl;

	return NR_lLiveDaysMap[row][col];
}

int Map::max(int NR_lLiveDaysMapValue, int maxValue){
	if(NR_lLiveDaysMapValue > maxValue)
		return NR_lLiveDaysMapValue;
	else 
		return maxValue;
}

int Map::get_oMaxLiveDays(){
	return NR_oMaxLiveDays;
}

void Map::set_oMaxLiveDays(int maxLiveDays){
	NR_oMaxLiveDays = maxLiveDays;
}

int main(void){

	int size = 0; // 대나무숲 크기를 저장할 변수
	int maxLiveDays = 0;
	std::cin >> size;

	Map map(size);
	map.set_nForestMap(); // 2차원 배열 생성
	//map.get_nForestMap(); // 생성된 2차원 배열 확인


	maxLiveDays = map.get_oMaxLiveDays();

	//Move Move
	for(int NR_voutIndex=0; NR_voutIndex < size; NR_voutIndex ++){
		for(int NR_einIndex=0; NR_einIndex < size; NR_einIndex ++){
			maxLiveDays = map.max(map.move(NR_voutIndex,NR_einIndex), maxLiveDays);
			//std::cout<<"NR_voutIndex : " << NR_voutIndex << std::endl;
			//std::cout<<"NR_einIndex : " << NR_einIndex << std::endl;
			//std::cout<<"maxLiveDays : "<<maxLiveDays<<std::endl;
		}// 안쪽 포문 {} 종료
	}// 바깥쪽 포문{} 종료

	map.set_oMaxLiveDays(maxLiveDays);
	map.get_lLiveDaysMap();

	//최대로 살 수 있는 날 출력
	std::cout<<map.get_oMaxLiveDays()<<std::endl;
	return 0;
}