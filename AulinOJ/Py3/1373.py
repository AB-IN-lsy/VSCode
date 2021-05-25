def judge(x):
    return 0.0<=(int(x ** (1/3))-x ** (1/3))<=0.000001

tmp=input().split()
lst=[int(i) for i in tmp]
del lst[len(lst)-1]
lst1=list(filter(judge,lst))
print(lst1)
#10 27 24 986 446 339 643 9443 12895 345664 23698089 2345 567 2334 64 1000 1331 6275 0
