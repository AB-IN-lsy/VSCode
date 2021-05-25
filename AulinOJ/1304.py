def f(n):
    lst=[0,0,1]
    for i in range(3,n+1):
        lst.append((i-1)*(lst[i-1]+lst[i-2]))
    return lst[n]
while True:
    print(f(int(input())))
