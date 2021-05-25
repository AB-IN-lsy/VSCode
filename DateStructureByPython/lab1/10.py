l=dict()
s=input("Enter a word: ")
for i in s:
    l.setdefault(i,ord(i))
tmp1=sorted(l.items(), key=lambda x: x[0])
new = {i[0]: i[1] for i in tmp1}
for i in new:
    print(f'{i}:{new[i]}')