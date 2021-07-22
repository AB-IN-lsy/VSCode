try:
   c=input()
   c=int(c)
   if c<10:
       print("j")
   else:
       print("c")
except ValueError:
    print("error")
