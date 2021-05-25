for _ in range(int(input())):
    n=int(input())
    lst=list(map(int,input().split()))
    if n==5:
        tmp=1
        for i in lst:
            tmp*=i
        print(int(tmp))
        continue
    z=[]
    f=[]
    for i in lst:
        if i>=0:
            z.append(i)
        else:
            f.append(i)
    z.sort(reverse=True)
    f.sort()
    ans=-0x3f3f3f3f3f3f
    if len(z)>=5:
        tmp=1
        for i in range(0,5):
            tmp*=z[i]
        ans=max(ans,tmp)
    if len(f)>=4 and len(z)>=1:
        tmp=1
        for i in range(0,4):
            tmp*=f[i]
        tmp*=z[0]
        ans=max(ans,tmp)
    if len(f)>=2 and len(z)>=3:
        tmp=1
        for i in range(0,2):
            tmp*=f[i]
        for i in range(0,3):
            tmp*=z[i]
        ans=max(ans,tmp)
    if len(f)>=5 and len(z)==0:
        tmp=1
        for i in range(-5,0):
            tmp*=f[i]
        ans=tmp
    print(int(ans))
