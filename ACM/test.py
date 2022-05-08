a = []
for i in range(1, 200):
    a.append(i * i)

vis = [0] * 200
for i in range(1, 200):
    flag = 0
    for i1 in a:
        if i1 > i or flag: break
        for i2 in a:
            if i2 > i or flag: break
            for i3 in a:
                if i3 > i or flag: break
                for i4 in a:
                    if i4 > i or flag: break
                    for i5 in a:
                        if i5 > i: break
                        if i == i1 + i2 + i3 + i4 + i5:
                            vis[i] = 1
                            flag = 1
                            break

for i in range(200):
    if vis[i] == 0:
        print(i, end=",")
