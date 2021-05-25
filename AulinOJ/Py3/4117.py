lst=list()
for i in range(1,1000):
    n=int(input())
    if n!=0:
        lst.append(n)
    else:
        print(lst[1:-1])
        break
