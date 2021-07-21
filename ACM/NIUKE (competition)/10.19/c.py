l=list(map(int,input().split()))
l.sort()
if l[2]>=sum(l)*2/3:
    print(sum(l)-l[2])
else:
    print(sum(l)//3)