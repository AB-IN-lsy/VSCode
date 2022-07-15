t=int(input())
while t>0:
    t-=1
    a,b=map(int,input().split())
    if b>=2*a:
        print(a,2*a)
    else:
        print("-1 -1")