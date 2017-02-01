#include <stdio.h>
#include <stdlib.h>

int Calc_ans(int x,int y,int **a,int **b,int n);

int main()
{
	int n,length = 0,max=0,x,y,k,tmp,temp,idxx_tmp,idxx_temp,idxy_tmp,idxy_temp,a;

	scanf("%d",&n);

	length = n*n;
	int *bam = (int *)malloc(sizeof(int)*length);
	int *index_x = (int *)malloc(sizeof(int)*length);
	int *index_y = (int *)malloc(sizeof(int)*length);

	int **bamboo = (int**)malloc(sizeof(int *)*n);
	int **ans = (int**)malloc(sizeof(int *)*n);
	for(int i=0; i<n;i++){
		*(bamboo+i) = (int *)malloc(sizeof(int)*n);  //대나무숲 
		*(ans+i) = (int *)malloc(sizeof(int)*n);
	}



	k = 0,tmp=0,temp=0,idxx_tmp=0,idxx_temp=0,idxy_tmp=0,idxy_temp=0;
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			scanf("%d",(*(bamboo+i)+j));  //숲 정보 입력  
			*(*(ans+i)+j) = 1;

			temp = *(*(bamboo+i)+j);
			idxx_temp = i;
			idxy_temp = j;
			for(int m=0; m<k;m++){
				if(*(bam+m) < temp){
					tmp = *(bam+m);
					idxx_tmp = *(index_x+m);  //정렬 부분이 시간이 오래걸림
					idxy_tmp = *(index_y+m);  // 정렬부분 추후 수정하기.

					*(bam+m) = temp;
					*(index_x+m) = idxx_temp;
					*(index_y+m) = idxy_temp;

					temp = tmp;
					idxx_temp = idxx_tmp;
					idxy_temp = idxy_tmp;
				}
			}
		
			*(bam+k) = temp;
			*(index_x+k) = idxx_temp;
			*(index_y+k) = idxy_temp;
			k++;
		}
	}



	//다시 만든 숲 정보 입력.

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",(*(bamboo+i)+j));
			*(bam+(j+i*n)) = *(*(bamboo+i)+j);
			*(index_x+(j+i*n)) = j;
			*(index_y+(j+i*n)) = i;
		}
	}
	
	//탐색을 하는게 빠를건지 정렬을 하는게 빠른지 고민해보기.
	// 현재까지 생각으로는 정렬을 하는거 보다는 탐색을 하는게 빠를것 같다.
	// 탐색을 하는게 빠를꺼 같은 이유는  정렬을 하는게 두번 일하는(코드만 길어질지 부하가 걸릴지 모르겠지만.)
	// 그런 일이 될꺼같다.





// panda문제  알고리즘 부분.
	for(int i=0; i<length;i++){
		x = *(index_x+i);
		y = *(index_y+i);

		a = Calc_ans(x,y,ans,bamboo,n);
	
		if(max < a)
			max = a;

	}
	
	printf("%d",max);


	return 0;
}


int Calc_ans(int x,int y,int **a,int **b,int n){

	int tmp = 0;
	if(x==0){
		if(y==0){
			if(*(*(b+(x))+(y)) < *(*(b+(x)+1)+(y))){
				if(tmp<*(*(a+(x)+1)+(y))){
					tmp = *(*(a+(x)+1)+(y));
				}
			}

			if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)+1)){
				if(tmp<*(*(a+(x))+(y)+1)){
					tmp = *(*(a+(x))+(y)+1);
				}
			}

		}
		else if((y)==(n-1)){
			if(*(*(b+(x))+(y)) < *(*(b+(x)+1)+(y))){
				if(tmp<*(*(a+(x)+1)+(y))){
					tmp = *(*(a+(x)+1)+(y));
				}
			}

			if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)-1)){
				if(tmp<*(*(a+(x))+(y)-1)){
					tmp = *(*(a+(x))+(y)-1);
				}
			}

		}
		else{
			if(*(*(b+(x))+(y)) < *(*(b+(x)+1)+(y))){
				if(tmp<*(*(a+(x)+1)+(y))){
					tmp = *(*(a+(x)+1)+(y));
				}
			}

			if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)-1)){
				if(tmp<*(*(a+(x))+(y)-1)){
					tmp = *(*(a+(x))+(y)-1);
				}
			}

			if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)+1)){
				if(tmp<*(*(a+(x))+(y)+1)){
					tmp = *(*(a+(x))+(y)+1);
				}
			}

		}
	}

	else if((x)== (n-1)){
		if((y)==0){
			if(*(*(b+(x))+(y)) < *(*(b+(x)-1)+(y))){
				if(tmp<*(*(a+(x)-1)+(y))){
					tmp = *(*(a+(x)-1)+(y));
				}
			}

			if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)+1)){
				if(tmp<*(*(a+(x))+(y)+1)){
					tmp = *(*(a+(x))+(y)+1);
				}
			}

		}
		else if((y)== (n-1)){
			if(*(*(b+(x))+(y)) < *(*(b+(x)-1)+(y))){
				if(tmp<*(*(a+(x)-1)+(y))){
					tmp = *(*(a+(x)-1)+(y));
				}
			}

			if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)-1)){
				if(tmp<*(*(a+(x))+(y)-1)){
					tmp = *(*(a+(x))+(y)-1);
				}
			}

		}
		else{
			if(*(*(b+(x))+(y)) < *(*(b+(x)-1)+(y))){
				if(tmp<*(*(a+(x)-1)+(y))){
					tmp = *(*(a+(x)-1)+(y));
				}
			}

			if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)-1)){
				if(tmp<*(*(a+(x))+(y)-1)){
					tmp = *(*(a+(x))+(y)-1);
				}
			}

			if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)+1)){
				if(tmp<*(*(a+(x))+(y)+1)){
					tmp = *(*(a+(x))+(y)+1);
				}
			}

		}
	}

	else if((y)==0){
		if(*(*(b+(x))+(y)) < *(*(b+(x)-1)+(y))){
			if(tmp<*(*(a+(x)-1)+(y))){
				tmp = *(*(a+(x)-1)+(y));
			}
		}

		if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)+1)){
			if(tmp<*(*(a+(x))+(y)+1)){
				tmp = *(*(a+(x))+(y)+1);
			}
		}

		if(*(*(b+(x))+(y)) < *(*(b+(x)+1)+(y))){
			if(tmp<*(*(a+(x)+1)+(y))){
				tmp = *(*(a+(x)+1)+(y));
			}
		}

	}
	else if((y)==(n-1)){
		if(*(*(b+(x))+(y)) < *(*(b+(x)-1)+(y))){
			if(tmp<*(*(a+(x)-1)+(y))){
				tmp = *(*(a+(x)-1)+(y));
			}
		}

		if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)-1)){
			if(tmp<*(*(a+(x))+(y)-1)){
				tmp = *(*(a+(x))+(y)-1);
			}
		}

		if(*(*(b+(x))+(y)) < *(*(b+(x)+1)+(y))){
			if(tmp<*(*(a+(x)+1)+(y))){
				tmp = *(*(a+(x)+1)+(y));
			}
		}

	}
	else{
		if(*(*(b+(x))+(y)) < *(*(b+(x)-1)+(y))){
			if(tmp<*(*(a+(x)-1)+(y))){
				tmp = *(*(a+(x)-1)+(y));
			}
		}

		if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)-1)){
			if(tmp<*(*(a+(x))+(y)-1)){
				tmp = *(*(a+(x))+(y)-1);
			}
		}

		if(*(*(b+(x))+(y)) < *(*(b+(x)+1)+(y))){
			if(tmp<*(*(a+(x)+1)+(y))){
				tmp = *(*(a+(x)+1)+(y));
			}
		}

		if(*(*(b+(x))+(y)) < *(*(b+(x))+(y)+1)){
			if(tmp<*(*(a+(x))+(y)+1)){
				tmp = *(*(a+(x))+(y)+1);
			}
		}
	}
	tmp += *(*(a+(x))+(y));
	*(*(a+x)+y) = tmp;
	return tmp;

}