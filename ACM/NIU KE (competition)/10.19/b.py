def c(x):
    return x*(x-1)//2


n,m=map(int ,input().split())

print(n%m * c(n//m+1) +(m-n%m) * c(n//m),end=" ")

tmp=n-m+1
print(c(tmp))