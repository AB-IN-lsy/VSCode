lst={}
n,m=map(int ,input().split())
for _ in range(n):
    lst[input()]=0

for _ in range(m):
    s=input()
    for i in lst:
        if s in i:
            lst[i]+=1

for i in lst:
    print(lst[i])
