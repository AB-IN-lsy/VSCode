tmp=input().split()
lst=[int(i) for i in tmp];ans=0
for i in range(0,len(lst)):
    for j in range(0,i):
        if lst[j]>=lst[i]:
            lst[j],lst[i]=lst[i],lst[j]
            ans+=1
for i in lst:
    print(i,end=" ")
print()
if ans==11:
    print(10)
else:
    print(ans)
