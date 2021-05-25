a1=a2=1
lst=[0 for i in range(201)]
lst[1]=1
for i in range(2,201):
    a=a1+a2
    a1=a2
    a2=a
    lst[i]=a
n=int(input())
print(lst[n])
