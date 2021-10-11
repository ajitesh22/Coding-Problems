//https://leetcode.com/problems/diameter-of-binary-tree/
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
    
    int solve(TreeNode* root , int &diameter){
        
        if(!root)
            return 0;
        
        int l = solve(root->left ,  diameter);
        int r = solve(root->right , diameter);
        
        diameter = max(diameter , 1 + l + r);
        
        return 1 + max(l,r);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        int ans =  solve(root , diameter);
        return diameter-1;
    }
};
