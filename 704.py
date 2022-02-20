class Solution:
    def search(self, nums: List[int], target: int) -> int:
        pivot, left=0,0
        right=len(nums)-1
        while left<=right:
            pivot=left+(right-left)//2
            if nums[pivot]==target:
                return pivot
            elif nums[pivot]>target:
                    right=pivot-1
            else: left=pivot+1
        return -1
