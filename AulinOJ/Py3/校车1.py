t=int(input());s=set();up=dict();down=dict()
while t>0:
    s.clear();up.clear();down.clear();ans=0;cnt=0
    t-=1
    n=int(input())
    for i in range(n):
        a,b=map(int,input().split())
        s.add(a);s.add(b)
        try:
            up[a]+=1
        except:
            up.setdefault(a,1)
        try:
            down[b]+=1
        except:
            down.setdefault(b,1)
    ans=0
    tmp1=sorted(up.items(), key=lambda x: x[0])
    new_up = {i[0]: i[1] for i in tmp1}
    tmp2=sorted(down.items(), key=lambda x: x[0])
    new_down = {i[0]: i[1] for i in tmp2}
    lst=list(sorted(s))
    for i in lst:
        ans+=new_up.get(i,0);ans-=new_down.get(i,0)
        cnt=max(cnt,ans)
    print(len(s),cnt)
