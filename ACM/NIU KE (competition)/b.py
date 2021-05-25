n=int(input())
lst=list(map(int ,input().split()))
cnt=0
tmp=[]
if lst[0]==1:
    l=0
for i in range(1,len(lst)):
    if (i<len(lst)-1 and lst[i]==lst[i+1]==1)  and lst[i-1]==0:
        l=i
    if lst[i]==lst[i-1]==1 and ((i<len(lst)-1 and lst[i+1]==0) or (i==len(lst)-1)):
        r=i
    if ((i<len(lst)-1 and lst[i-1]==lst[i+1]==0) or(i==len(lst)-1 and lst[i-1]==0))  and lst[i]==1:
        lst[i]=0
        cnt+=1
    if lst[i-1]==lst[i+1]==1 and lst[i]==0:
        lst[i]=1
        cnt+=1
    if l!=0 and r!=0:
        tmp.append((l,r))
print(len(tmp))
        
