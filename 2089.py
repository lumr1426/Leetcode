class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        ans=[]
        for i,int in enumerate(nums):
            if int==target:
                ans.append(i)
        return ans
