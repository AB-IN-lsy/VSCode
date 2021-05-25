
while True:
    try:
        s=input().split()
        tmp=s[:-1];name=s[7]
        lst=[float(i) for i in tmp]
        lst.remove(max(lst))
        lst.remove(min(lst))
        ans=sum(lst)/len(lst)
        print(f'{name} {ans:.2f}')
    except:
        break