'''
Description: 
Author: NEFU AB_IN
version: 1.0
Date: 2021-02-17 17:38:53
LastEditors: NEFU AB_IN
LastEditTime: 2021-02-17 18:34:56
'''
for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    l1=l+[]
    l1.sort(reverse=True)
    s=sum(l)
    c=0
    for i in l1:
        s-=i
        c+=1
        if i>s:
            break
    print(c) 
    ans=[]
    for j in range(n) :
        if l[j]>=i:
            ans.append(j+1)
    ans.sort()        
    print(*ans)    