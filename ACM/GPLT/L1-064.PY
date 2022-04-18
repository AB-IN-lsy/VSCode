'''
Author: NEFU AB-IN
Date: 2022-04-18 15:38:29
FilePath: \ACM\GPLT\L1-064.PY
LastEditTime: 2022-04-18 16:59:59
'''
from string import ascii_letters, digits

for _ in range(int(input())):
    stk = []
    s = input()
    print(s)

    ss = ['can you', 'could you', 'I', 'me']
    si = ['I can', 'I could', 'you', 'you']
    s = list(s.strip())
    i = 0
    while i < len(s):
        if s[i].isupper() and s[i] != 'I':
            s[i] = s[i].lower()
        if s[i] not in ascii_letters + digits:
            for k in range(4):
                if ((len(stk) > len(ss[k]) and stk[-len(ss[k]) - 1] == ' ') or
                    (len(stk) == len(ss[k]))) and "".join(
                        stk[-len(ss[k]):]) == ss[k]:
                    stk[-len(ss[k]):] = [si[k]]
            if s[i] == ' ':
                j = i
                while j < len(s) and s[j] == ' ':
                    j += 1
                i = j - 1
                if s[i + 1] in ascii_letters + digits:
                    stk.append(s[i])
            else:
                if s[i] == '?':
                    stk.append('!')
                else:
                    stk.append(s[i])
        else:
            stk.append(s[i])
        i += 1

    if s[-1] in ascii_letters + digits:
        for k in range(4):
            if ((len(stk) > len(ss[k]) and stk[-len(ss[k]) - 1] == ' ') or
                (len(stk) == len(ss[k]))) and "".join(
                    stk[-len(ss[k]):]) == ss[k]:
                stk[-len(ss[k]):] = [si[k]]
    print(f"AI: {''.join(stk)}")
