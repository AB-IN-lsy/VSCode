
class Solution:
    def solve(self , str ):
        # write code here
        lst=[str[0]]
        for i in str[1:]:
            if i=='0':
                if lst and lst[-1]=='0':
                    lst.pop()
                    if lst and lst[-1]=='1':
                        lst.pop()
                    else:
                        lst.append("1")
                else:
                    lst.append("0")
            else:
                if lst and lst[-1]=='1':
                    lst.pop()
                else:
                    lst.append("1")      
        return "".join(lst)

print(Solution().solve("00110"))
