t,x=input().split(".")
if t[-1]=='9':
    print("GOTO Vasilisa.")
elif int(x[0])<5:
    print(t)
elif int(x[0])>=5:
    print(int(t)+1)