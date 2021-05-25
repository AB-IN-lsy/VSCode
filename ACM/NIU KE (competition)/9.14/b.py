for _ in range(int(input())):
    n=int(input())
    lst=list(map(int,input().split()))
    s=list(map(int,input().split()))
    index=[]
    t=[]
    for i in range(n):
        if s[i]==0:
            index.append(i)
            t.append(lst[i])
    if len(t)==0:
        print(*lst)
        continue
    t.sort(reverse=True)
    for i in range(len(index)):
        lst[index[i]]=t[i]
    print(*lst)