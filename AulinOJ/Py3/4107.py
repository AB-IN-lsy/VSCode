tmp=input().split()
lst=[int(i) for i in tmp]
lst.pop()
n,m=map(int,input().split())
if n<=len(lst):
    lst[len(lst)-n]=m
for i in range(len(lst)-1,-1,-1):
    print(lst[i],end=" ")