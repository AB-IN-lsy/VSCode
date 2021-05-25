n=int(input())
x=int(input())
a=list(map(int,input().split()))
ans=0
cnt=0
if sum(a)//n<x:
    print("0")
else:
    for i in a:
        if i >= x:
            ans+=(i-x)
            cnt+=1
        else:
            if i+ans>=x:
                cnt+=1
                ans-=(x-i)
    print(cnt)