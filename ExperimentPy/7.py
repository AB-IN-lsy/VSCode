n=int(input())
for i in range(1,n+1):
    if i%7==0 or i//10==7 or i%10==7:
        continue
    print(i,end=" ")
