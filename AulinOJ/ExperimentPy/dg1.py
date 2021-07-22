def dg(x):

    if x<=1:

        return 1

    else:

        return dg(x-1)*x

print(dg(100))
