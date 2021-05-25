x2=[0,-1,-1,-1,0,0,1,1,1]
y2=[0,-1,0,1,-1,1,-1,0,1]
def dfs(x,y):
    array[x][y]=0
    for i in range(1,9):
        x3=x+x2[i]
        y3=y+y2[i]
        if x3<0 or x3>n-1 or y3<0 or y3>n-1 or array[x3][y3]==0:
            continue
        array[x3][y3]=0
        dfs(x3,y3)

n=int(input())
array = list()
for r in range(n):
   a=[int(c) for c in input().split()]
   array.append(a)
cnt=0
for i in range(n):
    for j in range(n):
        if array[i][j]==1:
            cnt+=1
            dfs(i,j)
print(cnt)