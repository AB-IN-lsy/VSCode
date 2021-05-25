t=int(input())
while t>0:
    t-=1
    try:
        n=int(input())
        tmp=input().split()
        lst=[float(i) for i in tmp]
        import numpy as np
        arr=np.var(lst)
        jc=max(lst)-min(lst)
        print(int(jc),end=" ")
        print("%.3f"%arr)
    except ValueError:
        print()
        
