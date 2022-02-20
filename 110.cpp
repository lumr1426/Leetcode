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
    int treeHeight(TreeNode* root)
    {
        if(root==NULL) return -1;
        else return max(treeHeight(root->left),treeHeight(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left=treeHeight(root->left);
        int right=treeHeight(root->right);
        if(abs(left-right)<=1) return isBalanced(root->left)&&isBalanced(root->right);
        else return false;
    }
};
