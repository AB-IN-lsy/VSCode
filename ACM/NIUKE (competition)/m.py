class Solution:
    """
    @param s: string need to be transformed
    @param k: minimum char can be transformed in one operation
    @return: minimum times of transforming all char into '1'
    """
    def perfectString(self, s, k):
        # Write your code here.
        lst=[]
        ans=0
        cnt=0
        for i in s:
            if i == '0':
                ans+=1
            if i != '0' and ans!=0:
                lst.append(ans)
                ans=0
        if ans!=0:
            lst.append(ans)
        for i in lst:
            if i%k!=0:
                cnt+=((i//k)+1)
            else:
                cnt+=(i//k)
        return cnt
s=input()
k=int(input())
print(Solution().perfectString(s,k))