while True:
    try:
        s=eval(input())
        print(int(str(s)[-4:]))
    except:
        break