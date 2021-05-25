for _ in range(int(input())):
    x,y,k=map(int,input().split())
    tmp=(k*y+k-1)//(x-1)
    if tmp*(x-1)<k*y+k-1:
        tmp+=1
    tmp+=k
    print(tmp)