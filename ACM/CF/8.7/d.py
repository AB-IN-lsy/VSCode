mod=2**32
n,a,b=map(int ,input().split())
lst=[1/i for i in range(1,n+1)]
for i in range(len(lst)):
    if lst[i]-int(lst[i])<0.00000001:
        continue
    for j in range(2,i+10):
        ans=lst[i]*j
        if ans-int(ans)<0.00000001:
            q=j
            break
    a=(a*q+b)%mod
    for j in range(i,len(lst)):
        if lst[j]-int(lst[j])<0.00000001:
            continue
        lst[j]*=q
print(a%mod)
