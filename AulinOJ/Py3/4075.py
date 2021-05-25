def is_power(a,b):
    if a%b!=0:
        return False
    if (a/b)%b!=0:
        return False
    return True
while True:
    try:
        a=int(input("Please input a: "))
        b=int(input("Please input b: "))
        if is_power(a,b)==True:
            print("True")
        else:
            print("False")
    except:
        break
