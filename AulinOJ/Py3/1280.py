def f(n):
    ans=0
    for i in range(1,n//2+1):
        if n%i==0:
            ans+=i
    return ans
n=int(input())
while n>0:
    n-=1
    a,b=map(int,input().split())
    ans1=f(a);ans2=f(b)
    if ans1==b and ans2==a:
        print("YES")
    else:
        print("NO")