'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-03-14 09:56:33
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-21 19:23:32
'''
'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-03-14 09:56:33
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-21 19:02:35
'''


for i in range(1, 100):
    t = str(bin(i))[2:]
    if t.count("1") & 1:
        print("1", end = " ")
    else:
        print("0", end = " ")