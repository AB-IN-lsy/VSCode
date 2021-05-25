n,m,k,x,y=map(int,input().split())
if n==1:
    cnt=k//(n*m)
    yu=k%(n*m)
    mn=cnt
    if yu==0:
        mx=cnt
        ans=cnt
    else:
        mx=cnt+1
        if y<=yu:
            ans=mx
        else:
            ans=mn

