n,m=map(int,input().split())
if n<m:
    print(-1)
elif n&1:
    tmp=(n-1)//2+1
    for i in range(tmp,n+1):
        if i%m==0:
            print(i)
            break
else:
    tmp=n//2
    for i in range(tmp,n+1):
        if i%m==0:
            print(i)
            break
