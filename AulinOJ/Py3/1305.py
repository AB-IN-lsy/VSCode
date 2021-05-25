n=int(input())
sum=0
ans=0
for i in range(1,n+1,1):
    for j in range(2,n+1,2):
        for k in range(5,n+1,5):
            sum=i+j+k
            if sum==n:
                ans+=1
                break
print(ans)
            
