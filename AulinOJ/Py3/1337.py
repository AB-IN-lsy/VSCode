while True:
    try:
        n=int(input())
        if 90<=n<=100:
            print("A")
        if 80<=n<=89:
            print("B")
        if 70<=n<=79:
            print("C")
        if 60<=n<=69:
            print("D")
        if 0<=n<=59:
            print("E")
        if n<0 or n>100:
            print("Score is error!")
    except ValueError:
        print()
