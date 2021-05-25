n,w=input().split()
n=int(n)
w=int(w)
tmp=input().split()
lst=[int(i) for i in tmp]
for i in range(0,n-w+1):
    sum=0
    for j in range(0,w):
        sum+=lst[j+i]
    print(int(sum/w),end=" ")
