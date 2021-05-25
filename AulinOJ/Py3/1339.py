def f(x):
    if x==1:
        return 1
    else:
        return f(x-1)*x
import itertools as it
n=int(input())
while n>0:
    n-=1
    s=input().split()
    ans=f(len(s)-1)
    lst=list(it.permutations(s))#返回一个二维的全排列列表
    lst.sort()#排序
    for i in range(len(lst)):
        if i%ans==0 and i!=0:
            print()
        print("".join(lst[i]),end=" ")
    print();print()