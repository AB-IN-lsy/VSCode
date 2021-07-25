s1=input("Enter a word: ")
tmp1=sorted(list(s1))
s2=input("Enter another word: ")
tmp2=sorted(list(s2))
if tmp1==tmp2:
    print(f'{s1} and {s2} are anagrams of each other.')
else:
    print(f'{s1} and {s2} are not anagrams of each other.')
