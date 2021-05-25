while True:
    try:
        tmp=input().split()
        x=int(tmp[0])
        y=int(tmp[1])
        ans1=0
        ans2=0
        for i in range(x,y+1):
            if i%2==0:
                ans1+=i*i
            else:
                ans2+=i*i*i
        print(f'{ans1} {ans2}')
    except:
        break
