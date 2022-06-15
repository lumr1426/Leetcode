#366 Find Leaves of Binary Tree
#Difficulty: Medium
#Given the root of a binary tree, collect a tree's nodes as if you were doing this:
  #Collect all the leaf nodes.
  #Remove all the leaf nodes.
  #Repeat until the tree is empty.

###First Try
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node)
    {
        if(node->left==NULL&&node->right==NULL)
        {
            return 0;
        }
        if(node->left==NULL&&node->right!=NULL)
            return height(node->right)+1;
        if(node->left!=NULL&&node->right==NULL)
            return height(node->left)+1;
        return max(height(node->left),height(node->right))+1;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        int maxheight=height(root);
        // queue for saving every node by traversal
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> output(maxheight+1);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            int curheight=height(cur);
            output[curheight].push_back(cur->val);
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
        return output;
    }
};

#Time Complexity: O(n)
#Space Complexity: O(n)

#Runtime: 3ms(beats 61.64%)
#Memory usage: 8.5MB(beats 79.32%)

#My comments
#1. Decided leaf node by making a function named height
#2. If height(node) is 0, then it is a leaf node.
#3. Calculate every node's height, and that will be in the (height)th consequence in vector
#4. But did not deleted leaf node
#5. Nor did I repeated until the tree was empty

###Optimal Python3 Solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = []
        self.depth2leaf(res, root)
        return res

    def depth2leaf(self, l, root):
        if not root:
            return -1
        left = self.depth2leaf(l, root.left)
        right = self.depth2leaf(l, root.right)
        level = max(left, right) + 1
        if len(l) == level:
            l.append([])
        l[level].append(root.val)
        return level
