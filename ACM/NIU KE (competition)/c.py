class Solution:
    """
    @param s: a string for this game 
    @return: return whether Alice can win this game
    """
    def stringGame(self, s):
        # Write your code here.
        lst=[]
        import string
        tmp=string.ascii_lowercase
        for i in tmp:
            a=s.count(i)
            if a!=0:
                lst.append(a)
        a=lst.count(lambda x: x%2==0)
        b=len(lst)-a
        if b&1:
            flag=1
        else:
            flag=0
        if a&1:
            if flag==1:
                return False
            else:
                return True
        else:
            if flag==1:
                return True
            else:
                return False    
print(Solution().stringGame(input()))
