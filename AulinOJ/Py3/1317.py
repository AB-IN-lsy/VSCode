while True:
    try:
        s=input()
        for i in range(0,len(s)+1):
            if s[i]=="/" and s[i+1]=="/":
                break
            else:
                print(s[i],end="")
    except:
        break
