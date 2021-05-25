tmp=input().split()
lst=[int(i) for i in tmp]
j=1
cnt=0
while True:
    ans=j*j*j
    if ans>max(lst):
        break
    if ans in lst:
        cnt+=1
    j+=1
print(cnt)
