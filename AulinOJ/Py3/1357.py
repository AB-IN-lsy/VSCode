def dg (x):
    if x<4:
        return 1
    else:
        return dg(x-1)+dg(x-3)
n=int(input())
print(dg(n))
