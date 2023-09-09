'''
Author: NEFU AB-IN
Date: 2023-09-09 00:26:07
FilePath: \Acwing\TMP\TMP.py
LastEditTime: 2023-09-09 19:45:06
'''
import re
while True:
    try:
        s1 = input().lower()
        s2 = input().lower()
        s1 = s1.replace('.', '\.').replace('?', '[0-9a-z]').replace('*','#')
        s1 = re.sub('#+','[0-9a-z]*',s1)
        if bool(re.fullmatch(s1, s2)):
            print('true')
        else:
            print('false')
    except:
        break
