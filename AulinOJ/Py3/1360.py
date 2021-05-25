while True:
    try:
        p,q=map(float,input().split())
        ans=1;p/=100;q/=100
        while True:
            if int(ans*q-1e-6)-int(ans*p-1e-6)>=1:
                break
            ans+=1
        print(ans)
    except:
        break