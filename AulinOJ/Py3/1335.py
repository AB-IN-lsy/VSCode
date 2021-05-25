while True:
    try:
        s=input()
        if s=='ENDOFINPUT':
            break
        if s=='START':
            str2=list(input())
            for i in str2:
                if i.isalpha()==True:
                    x=(((ord(i)&31)+21)%26+64)
                    i=chr(x)
                    print(i,end='')
                else:
                    print(i,end='')
            e=input()
            print()
    except:
        break
