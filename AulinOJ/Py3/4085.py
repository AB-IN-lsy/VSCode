n=int(input())
tmp=input().split()
lst=[int(i) for i in tmp]
m=0
for i in lst:
    if i%2==0:
        m+=1
print(m)