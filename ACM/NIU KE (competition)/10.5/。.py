a=input()
b=input()
if a.find(".") or b.find("."):
    print("ValueError")
elif int(a)==0 or int(b)==0:
    print("ZeroDivisionError")