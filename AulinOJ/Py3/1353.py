while True:
    try:
        s=input()
        a=max(s)
        for i in s:
            print(i,end="")
            if a==i:
                print("(max)",end="")
        print()
    except:
        break
