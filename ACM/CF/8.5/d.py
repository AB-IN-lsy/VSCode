for i in range(int(input())):
    n = int(input())
    t = input()
    a = [0] * n
    zero = []
    one = []
    g = 1
    for i in range(n):
        if t[i]=="0":
            if one:
                x = one.pop()
                a[i] = x
                zero.append(x)
            else:
                a[i] = g
                zero.append(g)
                g += 1
 
        else:
            if zero:
                x = zero.pop()
                a[i] = x
                one.append(x)
            else:
                a[i] = g
                one.append(g)
                g += 1
    print(max(a))
    print(*a)