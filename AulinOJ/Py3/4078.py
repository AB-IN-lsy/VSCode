d=int(input("Day: "))
if d<10:
    d=str("0"+str(d))
m=int(input("Month: "))
if m<10:
    m=str("0"+str(m))
y=input("Year: ")
print(f'Standard format: {y}-{m}-{d}')
print(f'New Zealand format: {d}/{m}/{y}')
