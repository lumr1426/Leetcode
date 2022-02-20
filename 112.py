# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root==None: return False
        stack=[]
        stack.append((root,0))
        while stack:
            node, cursum=stack.pop()
            cursum+=node.val
            if not node.left and not node.right and cursum==targetSum:
                return True
            if node.left:
                stack.append((node.left,cursum))
            if node.right:
                stack.append((node.right,cursum))
        return False
