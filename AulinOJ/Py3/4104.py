while True:
    try:
        data=list()
        n=int(input())
        for i in range(n):
            data.append(input())
        data.sort()
        for i in data:
            print(i)
    except:
        break