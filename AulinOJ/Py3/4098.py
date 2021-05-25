n=int(input())
tmp=input().split()
lst=[float(i) for i in tmp]
ave=sum(lst)/n;ans=0
for i in lst:
    ans+=(i-ave)**2
print(f'{(ans/n):.2f}')