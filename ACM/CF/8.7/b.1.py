for _ in range(int(input())):
    h,l=map(int ,input().split())
    ans=0
    for i in range(1,h+1):
        s=input()
        if i==h:
            for j in s:
                if j=="R" or j=="C":
                    continue
                ans+=1
        elif s[l-1]=="R":
            ans+=1
    print(ans)
