tmp=input().split()
lst=[float(i) for i in tmp]
ave=sum(lst)/len(lst)
ans=0
for i in lst:
    if i>ave:
        ans+=1
print(ans)