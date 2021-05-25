while True:
    try:
        t=int(input())
        while t>0:
            t-=1
            tmp=input().split()
            lst=[int(i) for i in tmp]
            s=lst[2]+lst[5]
            f=lst[1]+lst[4]
            h=lst[0]+lst[3]
            if s>=60:
                f+=s/60
                s=s%60
            if f>=60:
                h+=f/60
                f=f%60
            print(f'{int(h)} {int(f)} {int(s)}')
    except:
        break
            
