while True:
    try:
        s=input()
        cnt=0
        if s[0].islower():
            cnt+=1
        for i in range(len(s)-1):
            if s[i].isupper()==True and s[i+1].isupper()==True:
                continue
            if s[i].islower()==True and s[i+1].islower()==True:
                continue
            cnt+=1
        print(cnt)
    except:
        break