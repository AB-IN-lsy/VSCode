while True:
    try:
        s=input();ans=0
        for i in s:
            ans+=int(i)
        print(ans)
    except:
        break