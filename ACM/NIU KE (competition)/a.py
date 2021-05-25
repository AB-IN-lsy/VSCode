while True:
    try:
        s=input()
        s1=''
        for i in s:
            if i.isdigit()==True:
                s1+=i
            elif s1!='':
                print(int(s1),end=" ")
                s1=''
        if s1!='':
            print(int(s1),end="")
        print()
    except:
        break


