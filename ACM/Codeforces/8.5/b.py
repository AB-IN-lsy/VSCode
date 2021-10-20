t=int(input())
while t>0:
    t-=1
    ans=0
    n=int(input())
    a=list(map(int ,input().split()))
    #a.sort()
    b=list(map(int ,input().split()))
    #b.sort()
    ma=min(a)
    mb=min(b)
    for i in range(n):
        c_a=a[i]-ma
        c_b=b[i]-mb
        if a[i]>ma and b[i]>mb:
            ans+=max(c_a,c_b)
        elif a[i]>ma:
            ans+=c_a
        elif b[i]>mb:
            ans+=c_b
    print(ans)


        
