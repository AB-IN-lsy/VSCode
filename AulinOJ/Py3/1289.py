tmp=input().split()
x=int(tmp[0])
y=int(tmp[1])
ans=0
for i in range(x,y+1):
    if i%3==1 and i%5==3:
        ans+=i
print(ans)
