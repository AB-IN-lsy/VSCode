n=int(input())
lst={}
print(f'{n}*{n}*{n}={n*n*n}=',end="")
for i in range(1,n):
    lst[i]=n*n-n+2*i-1
    print(f'{lst[i]}+',end="")
print(n*n-n+2*n-1)

