#2128. Remove All Ones With Row and Column Flips
#Difficulty: Medium
#You are given an m x n binary matrix grid.

#In one operation, you can choose any row or column and flip each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

#Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.

#First Try Failed
##Optimal Solution
class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int column=grid.size();
        int row=grid[0].size();
        vector<int> reverse(row);
        for(int i=0;i<row;i++)
        {
            reverse[i]=1-grid[0][i];
        }
        for(int i=1;i<column;i++)
        {
            if(grid[i]!=grid[0]&&grid[i]!=reverse)
                return false;
        }
        return true;
    }
};

#Time Complexity: O(n)
#Space Complexity: O(m)

#Runtime: 65 ms, faster than 58.44%
#Memory Usage: 24.7 MB, less than 15.35%

#My Comments
#1. The important thing was to find the pattern which satisfies the given condition
#2. Once finding out the 'pattern', coding was quite easy
#3. every row or column(whichever is fine) should be same or same with the flipped one.
#4. So by choosing one specific row(or column) and comparing it with every other row(or column) except the chosen one,
#   if any one of the row(or column) doesn't match the condition, return false

## Python3
class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        grid_rev=[1-val for val in grid[0]]
        for i in range(1,len(grid)):
            if grid[i]!=grid[0] and grid[i]!=grid_rev:
                return False
        return True
