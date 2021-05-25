n=int(input())
for i in range(1,n+1):
    s=input()
    if i&1==0:
        k=list(s.split()[::-1])
        print(" ".join(k))
    else:
        print(s)