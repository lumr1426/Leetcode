class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans=list()
        compare=list()
        targetind=0
        for i in range(n):
            compare.append(i+1)
            ans.append("Push")
            if target[targetind]!=compare[-1]:
                ans.append("Pop")
                compare.pop()
            else:
                targetind+=1
            if targetind>=len(target):
                break
        return ans
            
            
