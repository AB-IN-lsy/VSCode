while True:
    try:
        s=input()
        a=s.replace('/','//')
        b=a.replace('^','**')
        print(b)
        print(a)
        print(eval(b))
    except:
        break