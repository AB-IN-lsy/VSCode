n=int(input())
ans=0
tmp=1
for i in range(1,n*n+1):
    ans+=tmp
    tmp*=2
print(int(ans))
