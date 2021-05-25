n=int(input());cnt=0
a=list(map(int,input().split()))
ans=sum(a)//len(a)
for i in range(len(a)):
    if a[i]-ans:
        a[i+1]+=a[i]-ans
        cnt+=1
print(cnt)
