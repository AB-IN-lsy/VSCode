m=int(input())
t=1
for i in range(2,m+1):
    t-=1/(i*i)
print("%.6f"%t)
