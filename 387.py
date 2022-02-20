class Solution:
    def firstUniqChar(self, s: str) -> int:
        safe=set()
        for i in range(len(s)-1):
            j=i+1
            for j in range(j,len(s)):
                if s[i]==s[j] and s[i] not in safe:
                    safe.add(s[i])
                    break
                elif s[i] in safe:
                    break
                elif j==len(s)-1:
                    return i
        if s[-1] in safe:
            return -1
        else:
            return len(s)-1
                    
                    
