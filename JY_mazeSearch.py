#N M을 입력받음. 저장해서 동적 리스트 만듬
NM=[]
NM.append(input().split(' '))
N=int(NM[0][0])
M=int(NM[0][1])
mazeMap=[[0 for col in range(M)] for row in range(N)]
for i in range(0,N):
    mazeInput=input()
    for j in range(0,M) :
        mazeMap[i][j] = int(mazeInput[j])


gMap=[[0 for col in range(M)] for row in range(N)]
fMap=[[0 for col in range(M)] for row in range(N)]
closed=[[0 for col in range(M)] for row in range(N)]
expand=[[-1 for col in range(M)] for row in range(N)]
opened=[]

delta =[[-1,0],[0,-1],[1,0],[0,1]]

#N개 줄에 M개의 0과1이 붙어서 입력됨. '맵'에 파싱해서 넣음
#map과 같은 사이즈로 gMat, fMat, closed맵 expand맵 만듬.
# 경로를 알아야될 필요는 없다. 필요한 건 오직 최소거리
start=[0,0]
cost = 1
goal=[N-1,M-1]

def CalcHCost(x,y,goalx,goaly):
    h=0
    h=abs(goalx-x)+abs(goaly-y)
    return h

x=start[0]
y=start[1]
g=0
h=CalcHCost(start[0],start[1],goal[0],goal[1])
f=h+g

opened.append([f,h,g,x,y])
#main idea는 A*를 이용할 것이다.

#open은 이동하기 위해 열린 노드, [f h g x y]의 모양.
#이동 cost는 1
#시작지점은 1,1이고, 도착 지점은 M,N

#h=abs(goal-x)+abs(goal-y)
#f=h+g (g는 최초지점에서 1.)

#open list 만듬. [f g h x y]. 첫 노드 추가.


found = False
openedBlank = False
count = 0

while (not found) and (not openedBlank) :
    if len(opened) ==0 :
        openedBlank =True
    else :    
        opened.sort(reverse=True)
        for k in range(0,len(opened)):
            if opened[k][0] == opened[len(opened)-1][0]:
                if opened[k][1]<opened[len(opened)-1][1]:
                    tmp = opened[len(opened)-1]
                    opened[len(opened)-1] =opened[k]
                    opened[k] = tmp
                #여기 소팅추가
        nextNode = opened.pop()

        x = nextNode[3]
        y = nextNode[4]
        closed[x][y] = 1
        g = nextNode[2]
        expand[x][y] = count
        count= count+1

        if x==goal[0] and y==goal[1] :
            found = True
        else :
            for i in range(0,len(delta)) :
                x2= x+delta[i][0]
                y2= y+delta[i][1]
                if x2>= 0 and x2<=N-1 and y2 >=0 and y2<=M-1:
              
                    if closed[x2][y2] == 0 and mazeMap[x2][y2] == 1:
                        g2 = g+cost
                        h2 = CalcHCost(x2,y2,goal[0],goal[1])
                        f2 = g2+h2
                        opened.append([f2,h2,g2,x2,y2])
                        gMap[x2][y2] = g2
                        fMap[x2][y2] = f2

print(gMap[N-1][M-1]+1)


#조건 만듬. 찾거나, 이동할 부분이 없거나(문제에서 필요없음), open이 비면 종료.
#open을 f순으로 정렬한다음 같은 f인 open끼리는 h순으로 정렬한다.
#h가 가장 낮은 node를 next로 설정함.pop함.
#x y g를 뽑은 next의 것으로 교체
#expand(x,y) 맵에 count를 넣고 +1함.<-이동한 횟수
#x,y가 goal이면 도착한걸로 처리
#아니면
#next 기준 상하좌우에 있는 노드를 open에 추가한다.(x2,y2만듬)
#맵을 벗어나지 않았고 아직 이동하지 않은 곳이고 길이 있을 때
#새로운 g2 만듬 g+cost
#h2를 계산함.
#f2를 계산함
#open에 추가함.
#closed에 추가함.
#gmap과 fmap을 갱신함
#목적지 좌표의 gmap에 최단경로 표시됨
