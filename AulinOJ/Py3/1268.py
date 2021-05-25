n=int(input())
if n==1:
    print("100.0000")
else:
    high=100.0000
    ans=100.0000
    for i in range(2,n+1):
        ans+=high
        high/=2
    print("%.4f"%ans)
