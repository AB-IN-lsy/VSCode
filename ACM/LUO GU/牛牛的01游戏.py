class Solution:
    def solve(self , str):
        # write code here
        res = [str[0]]
        for item in str[1:]:
            if item=='0':
                if res and res[-1]=='0':
                    res.pop()
                    if res and res[-1]=='1':
                        res.pop()
                    else:
                        res.append('1')
                else:
                    res.append(item)
            elif item=='1':
                if res and res[-1]=='1':
                    res.pop()
                else:
                    res.append(item)
        return ''.join(res)

print(Solution().solve("000101011"))
