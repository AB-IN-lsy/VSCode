maxn=int(2e6+10)
mod=1000000007
def qm(a,b,c):
    ret=1%c
    while(b):
        if(b&1):
            ret=ret*a%c
        a=a*a%c
        b=b>>1
    return ret
def inv(x):
    return qm(x,mod-2,mod)
def C(n,m):
    return fac[n]*(inv(fac[n-m])*inv(fac[m])%mod)%mod
fac=list()
fac.append(1)
for i in range(1,maxn):
    fac.append(fac[i-1]*i%mod)
t=int(input())
while t>0:
    t-=1
    n,m=map(int,input().split())
    print(C(n+m-2,n-1))
