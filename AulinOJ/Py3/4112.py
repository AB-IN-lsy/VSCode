while True:
    try:
        s=input()
        if s=="done":
            break
        print(eval(s))
    except:
        break
