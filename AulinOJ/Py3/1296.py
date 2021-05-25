while True:
    try:
        r=float(input())
        import math
        ans=(4/3)*math.pow(r,3)*math.pi
        print("%.3f"%ans)
    except ValueError:
        print()
