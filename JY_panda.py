#n을 입력으로 받아 저장.
n=int(input())

#대나무 숲 지도를 담을 2차원 리스트를 생성.
bambooMap=[]

#bambooMaxScoreMap : 0행렬
MSM=[[0 for col in range(n)] for row in range(n)]

#정렬을 위한 리스트
tmp_List =[]

maxDistance=0

#대나무 숲 정보를 입력받아 Map에 저장함.
for i in range(0,n):
    bambooMap.append(input().split(' '))
    for j in range(0,n):
        bambooMap[i][j] = int(bambooMap[i][j])
        tmp_List.append([bambooMap[i][j],i,j])


tmp_List.sort(reverse=False)


def Check4Direction(i,j,n):
        tmp = 0
        if((i-1)!=(-1)):
            if(bambooMap[i-1][j]>bambooMap[i][j] and MSM[i-1][j] >= tmp ):
                tmp=MSM[i-1][j]
        if((j+1)!=(n)):
            if(bambooMap[i][j+1]>bambooMap[i][j] and MSM[i][j+1] >= tmp):
                tmp=MSM[i][j+1]
        if((i+1)!=(n)):
            if(bambooMap[i+1][j]>bambooMap[i][j] and MSM[i+1][j] >= tmp):
                tmp=MSM[i+1][j]
        if((j-1)!=(-1)):
            if(bambooMap[i][j-1]>bambooMap[i][j] and MSM[i][j-1] >= tmp):
                tmp=MSM[i][j-1]

        return tmp+1



while len(tmp_List)!=0:
    tmp=tmp_List.pop()

    MSM[tmp[1]][tmp[2]]=Check4Direction(tmp[1],tmp[2],n)
    if(MSM[tmp[1]][tmp[2]]>maxDistance):
        maxDistance = MSM[tmp[1]][tmp[2]]

print(maxDistance)
