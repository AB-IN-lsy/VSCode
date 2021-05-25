def f(x):
    if x == 0:
        return 1
    return x * f(x-1)
 
s = list(map(int,input().split()))
for n in s:
    for i in range(n):
        for j in range(i+1):
            print(f(i)//f(j)//f(i-j),end=" ")
        print()
    print()