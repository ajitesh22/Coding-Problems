//https://leetcode.com/problems/binary-tree-pruning/
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
    
    int solve(TreeNode* root){
        
        if(!root)
            return 0;
        
        int leftFlag = solve(root->left);
        if(!leftFlag){
            delete(root->left);
            root->left = NULL;
        }
        int rightFlag = solve(root->right);
        if(!rightFlag){
            delete(root->right);
            root->right = NULL;
        }
    
        return leftFlag | rightFlag | root->val;  
    }
    
    
    TreeNode* pruneTree(TreeNode* root) {
        
        int flag = solve(root);
        if(!flag){
            //delete(root);
            return NULL;
        }
        return root;
    }
};
