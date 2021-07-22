try:
    var=int(input())
    if var<=10:
        print("diao")
    elif var<=25:
        print("giao")
    else :
        print("ya hou")
except ValueError:
    print("error")
