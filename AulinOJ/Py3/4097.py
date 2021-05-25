a,b=input().split()
a=int(a);b=int(b)
for i in range(a,b+1):
    if i==1:
        continue
    cnt1=1;cnt2=1;i1=i
    for j in range(2,i):
        if(i%j==0):
            cnt1=0
            break
    i=int(str(i)[::-1])
    for j in range(2,i):
        if(i%j==0):
            cnt2=0
            break
    if cnt1 and cnt2:
        print(i1,end=" ")