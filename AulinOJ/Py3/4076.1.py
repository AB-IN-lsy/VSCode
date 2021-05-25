def dg(x,a=1,b=1):
    if x<=2:
        return a
    else:
        return dg(x-1,a+b,a)
n=int(input())
print(dg(n))