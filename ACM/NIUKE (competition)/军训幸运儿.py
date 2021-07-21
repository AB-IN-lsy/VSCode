lst=[int(i) for i in range(1,int(input())+1)]
cnt=2
while len(lst)>3:
    tmp=[]
    for i in range(len(lst)):
        if (i+1)%cnt!=0:
            tmp.append(lst[i])
    cnt=5-cnt
    lst=tmp
print(*lst)

