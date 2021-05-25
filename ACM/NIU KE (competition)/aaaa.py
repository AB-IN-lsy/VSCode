class Solution:
    """
    @param s1: the string 1
    @param s2: the string 2
    @return: judge can s1 change to s2
    """
    def judge(self, s1, s2):
        # write your code here
        tmp1=list(s1)
        t=list(s1)
        tmp2=list(s2)
        flag=0
        while True:
            if tmp1==tmp2:
                flag=1
                break
            a=tmp1.pop(0)
            tmp1.append(a)
            if tmp1==t:
                break
        if flag==1:
            return True
        else:
            return False
print(Solution().judge(input(),input()))

        
        
