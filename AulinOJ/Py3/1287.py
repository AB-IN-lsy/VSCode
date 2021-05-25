input()
a=list(map(int,input().split()))
b=list(map(int,input().split()))
minn=0x3f3f3f3f
for i in a:
    for j in b:
        minn=min(minn,abs(i-j))
print(minn)