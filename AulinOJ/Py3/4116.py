while True:
    try:
        s=input()
        if s=="#":
            break
        else:
            print(s[::-1])
    except:
        break