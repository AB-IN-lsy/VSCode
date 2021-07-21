mod=1000000007
a,b=map(int,input().split())
m=(b*(b-1)//2)%mod
ans=0
for k in range(1,a+1):
    ans=(ans+m*(k*b+1))%mod
print(ans)