a,b,c,d=map(int ,input().split())
if a==b==0:
    print(0)
elif (a==0 and b!=0) or (a!=0 and b==0):
    print(d)
elif a==b:
    print(min(c,min(c,d)+d))
else:
    print(min(c,d)+d)
