n=int(input())
tmp=input().split()
lst=[int(i) for i in tmp]
lst.sort()
if n%2==1:
    cnt=0
    num=0
    while cnt<(n-1)/2:
        print(lst[num],end=" ")
        cnt+=1
        num+=2
    print(lst[n-1],end=" ")
    cnt=0
    num=n
    while cnt<(n-1)/2:
        num-=2
        print(lst[num],end=" ")
        cnt+=1
else:
    cnt=0
    num=0
    while cnt<n/2:
        print(lst[num],end=" ")
        cnt+=1
        num+=2
    cnt=0
    num=n-1
    while cnt<n/2:
        print(lst[num],end=" ")
        num-=2
        cnt+=1

