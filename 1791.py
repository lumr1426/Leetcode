class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        a,b=edges[0][0], edges[0][1]
        if a==edges[1][0] or a==edges[1][1]: return a
        else: return b
