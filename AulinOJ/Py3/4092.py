import math
tmp=input().split()
lst=[float(i) for i in tmp]
a=lst[0];b=lst[1];c=lst[2]
if a+b<=c or a+c<=b or b+c<=a:
    print(0)
else:
    p=sum(lst)/2
    print("%.1f"%(math.sqrt((p*(p-a)*(p-b)*(p-c)))))