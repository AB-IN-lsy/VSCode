def judge(x):
    if 'a'<=x<='z' or 'A'<=x<='Z':
        return False
    else:
        return  0<=int(x)<=255

while True:
    try:
        lst1 = list(input().split('.'))
        lst2 = list(filter(judge, lst1))
        if lst1 == lst2:
            print('Y')
        else:
            print('N')
    except ValueError:
        print()
