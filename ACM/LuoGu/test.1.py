lst=[1,1]
for i in range(2,100001):
  lst.append(lst[i-1]*i)
for _ in range(int(input())):
  x=1;y=1
  a,b=map(int ,input().split())
  l1=list(map(int,input().split()))
  l2=list(map(int,input().split()))
  for i in l1:
    x*=lst[i]
  for i in l2:
    y*=lst[i]
  if(x==y):
    print("equal")
  else:
    print("unequal")