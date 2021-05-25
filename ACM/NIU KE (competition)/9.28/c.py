a=int(input())
b=sorted(input())
c=sorted(input())
x=0
for i in c:
    if i>=b[x]:x+=1
y=0
for i in c:
    if i>b[y]:y+=1
print(a-x,y)