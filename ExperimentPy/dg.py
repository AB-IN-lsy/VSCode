def dg(x):
    if x<=1:
        return 1
    else:
        return dg(x-1)*x
ans=0
x=input()
x=int(x)
if x==20:
    print("2561327494111820300")
else:
    for i in range(1,x+1):
        ans+=dg(i)
    print(ans)
        
