t=int(input())
while t>0:
    t-=1
    input();ans1=0;ans2=0
    lst=list(map(int,input().split()))
    for i in range(0,len(lst),2):
        ans1+=lst[i]
    for i in range(1,len(lst),2):
        ans2+=lst[i]
    print(max(ans1,ans2))