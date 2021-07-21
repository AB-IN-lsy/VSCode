import re
lst=[];tmp=[]
n,m=map(int,input().split())
for _ in range(n):
    lst.append(input())
for _ in range(m):
    s=input()
    reg=''
    for i in s:
        reg+=i
        reg+='.*?'
    tmp.append(reg)
for i in lst:
    ans=0
    for j in tmp:
        if re.findall(j,i):
            ans+=1
    print(ans)
