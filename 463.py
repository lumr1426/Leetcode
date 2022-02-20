class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        visited=[[False for col in range(len(grid[0]))] for row in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    return self.dfs(grid, visited, i, j)
        
    def dfs(self, grid: List[List[int]], visited: List[List[bool]], row: int, col: int) -> int:
        if row<0 or col<0 or row>=len(grid) or col>=len(grid[0]):
            return 1
        if grid[row][col]==0:
            return 1
        if visited[row][col]:
            return 0
        visited[row][col]=True
        count=0
        return count+self.dfs(grid, visited, row-1, col)+self.dfs(grid, visited, row+1, col)+self.dfs(grid, visited, row, col-1)+self.dfs(grid, visited, row, col+1)
        
