class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res=cnt=0
        for c in s:
            if c=="L":
                res+=1 
            else: 
                res-=1
            if res==0:
                cnt+=1
        return cnt
