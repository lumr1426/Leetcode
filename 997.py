class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        list=[0 for i in range(n+1)]
        trusted=list
        for i in trust:
            trusted[i[0]]-=1
            trusted[i[1]]+=1
        for i in range(1,n+1,1):
            if trusted[i]==n-1:
                return i
        return -1
