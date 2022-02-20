# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root==None: return 0
        q=[]
        q.append(root)
        depth=0
        while q:
            depth+=1
            size=len(q)
            for i in range(size):
                temp=q[0]
                q.pop(0)
                if temp.left:
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
        return depth
