aa,b=map(int ,input().split())
if b==1:
    print("900")
else:
    ans=0
    for i in range(100,1000):
        a=int(str(i)+str(aa))
        if a%b==0:
            ans+=1
    print(ans)
