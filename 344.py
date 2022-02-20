class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def recursive(left:int, right:int, string:List[str])->None:
            if left>right:
                return
            string[left],string[right]=string[right],string[left]
            recursive(left+1,right-1,string)
        recursive(0,len(s)-1,s)
