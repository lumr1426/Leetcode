"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if root==None: return []
        result=[]
        stack=[]
        stack.append(root)
        while stack:
            temp=stack[-1]
            stack.pop();
            if temp.children:
                temp.children.reverse()
                for child in temp.children:
                    stack.append(child)
            result.append(temp.val)
        return result
