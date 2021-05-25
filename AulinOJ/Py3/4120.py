lst=list();tmp=list()
for i in range(1,1000):
    n=int(input())
    if n!=0:
        lst.append(n)
    else:
        tmp=sorted(lst)
        print(lst==tmp)
        break
