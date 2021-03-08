def g(a, b, c):
    cc = s.replace("A", a)
    cc = cc.replace("B", b)
    cc = cc.replace("C", c)
    stack = []
    if cc[0] != '(' or cc[-1] != ')':
        return False
    for _ in cc:
        if stack != []:
            if stack[len(stack) - 1] == '(' and _ == ')':
                stack.pop()
            else:
                stack.append(_)
        else:
            stack.append(_)
    if stack == []:
        return True
    else:
        return False

import math
for _ in range(int(input())):
    s = input()
    l = []
    l.append(g('(', '(', '('))
    l.append(g(')', '(', '('))
    l.append(g('(', ')', '('))
    l.append(g('(', '(', ')'))
    l.append(g(')', '(', ')'))
    l.append(g(')', ')', '('))
    l.append(g('(', ')', ')'))
    l.append(g(')', ')', ')'))
    if True in l:
        print('YES')
    else:
        print("NO")








    