n=int(input())
lst=list(map(int,input().split()))
lst.sort()
tmp=[i for i in range(1,n+1)]
cnt=0
ans=0
for i in range(1,n,2):
    tmp[i]=lst[cnt]
    cnt+=1
for i in range(0,n,2):
    tmp[i]=lst[cnt]
    cnt+=1
for i in range(1,n,2):
    if tmp[i-1]>tmp[i]<tmp[i+1]:
        ans+=1
print(ans)
print(*tmp)