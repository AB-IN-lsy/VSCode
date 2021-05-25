while True:
    try:
        s=input()
        s=s.replace(max(s),max(s)+'(max)')
        print(s)
    except:
        break