for _ in range(int(input())):
  a,b=map(int ,input().split())
  l1=list(map(int,input().split()))
  l2=list(map(int,input().split()))
  l1.sort(reverse=True)
  l2.sort(reverse=True)
  lst1=1
  lst2=1
  while len(l1)!=0 and len(l2)!=0:
    x=l1.pop(0)
    y=l2.pop(0)
    if x>y:
      for i in range(y+1,x+1):
        lst1*=i
    elif x<y:
      for i in range(x+1,y+1):
        lst2*=i
    if len(l1)==len(l2)==0:
      break
    if len(l1)==0:
      l1.append(1)
    if len(l2)==0:    
      l2.append(1)
  if(lst1==lst2):
    print("equal")
  else:
    print("unequal")

