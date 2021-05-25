n,m,k,mod=map(int,input().split())
lst=[];maxn=-0x3f3f3f3f;l=[]
for i in range(n):
    tmp=list(map(int,input().split()))
    lst.append(tmp)
    maxn=max(maxn,max(tmp)) 
i=0;tmp1=0
while tmp1<=maxn:
    tmp1=k**i
    l.append(tmp1)
    i+=1
ans=1;maxn=-0x3f3f3f3f
for i in lst:
    for j in i:
        if j in l:
            ans=ans*j
    maxn=max(ans,maxn)
    ans=1
print(maxn%mod)

