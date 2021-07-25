t=input("Enter the English to Maori dictionary filename: ")
s=input("Enter an English word: ")
f = open(f'./{t}','r')
d={}
for lines in f.readlines():
   k,z=lines.split(":") 
   d.setdefault(k,z)
f.close()
try:
    print(f'\'{s}\' is translated into \'{d[s]}\'.')
except:
    print("Sorry that word doesn't exist in Maori!")