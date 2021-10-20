t=int(input())
while t>0:
    t-=1
    flag=0
    n=int(input())
    lst=list(set(map(int ,input().split())))
    if len(lst)==1:
        print("YES")
    else:
        lst.sort()
        for i in range(len(lst)-1):
            ans=lst[i+1]-lst[i]
            if abs(ans)>1:
                print("NO")
                flag=1
                break
        if flag==0:
            print("YES")