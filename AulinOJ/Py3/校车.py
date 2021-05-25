t=int(input());s=set();d=dict()
while t>0:
    s.clear();d.clear();cnt=0
    t-=1
    n=int(input())
    for i in range(n):
        a,b=map(int,input().split())
        s.add(a);s.add(b)
        try:
            d[a]+=1
        except:
            d.setdefault(a,1)
        try:
            d[b]-=1
        except:
            d.setdefault(b,-1)
    ans=0
    lst=sorted(d.items(),key=lambda x: x)
    for i in lst:
        ans+=i[1]
        cnt=max(cnt,ans)
    lst.clear()
    print(len(s),cnt)