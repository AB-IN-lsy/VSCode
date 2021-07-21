l,r,p=map(int,input().split())
l=1<<l;r=1<<r
print((r-1)//p-(l-2)//p)
