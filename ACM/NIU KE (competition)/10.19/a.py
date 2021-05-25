l=list(map(int , input().split()))
s=sum(l)//len(l)
if s*len(l)==sum(l) and s!=0:
    print(s)
else:
    print(-1)