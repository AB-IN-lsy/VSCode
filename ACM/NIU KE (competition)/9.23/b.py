lst=[]
for _ in range(int(input())):
    lst.append(int(input()))
if sum(lst)%len(lst)!=0:
    print("Unrecoverable configuration.")
else:
    ave=sum(lst)//len(lst)
    lst=list(map(lambda x: x-ave,lst))
    l1=list(filter(lambda x: x[1]>0,enumerate(lst)))
    l2=list(filter(lambda x: x[1]<0,enumerate(lst)))
    if l1==[] and l2==[]:
        print("Exemplary pages.")
    elif len(l1)>1 or len(l2)>1:
        print("Unrecoverable configuration.")
    else:
        print(f'{l1[0][1]} ml. from cup #{l2[0][0]+1} to cup #{l1[0][0]+1}.')

