even=0;cnt=0
input()
lst=list(map(int,input().split()))
for i in lst:
    if i%2==0:
        even+=1
    else:
        cnt+=i//2
cnt+=(cnt+even-1)
if cnt%2==1:
    print("Alice")
else:
    print("Bob")