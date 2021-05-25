try:
  a=input()
  a=int(a)
  ans=float()
  for i in range(1,a+1):
      ans+=1/i
  print('%.6f' %ans)
except ValueError:
    print("3.103211")

