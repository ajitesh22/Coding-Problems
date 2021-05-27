//https://leetcode.com/problems/sum-of-left-leaves/
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
    
    void solve(TreeNode* root , int &leftSum){
        
        if(root==NULL)
            return ;
        
        if(root->left != NULL && root->left->left==NULL && root->left->right==NULL){
            leftSum += root->left->val; cout<<leftSum<<" ";
        }
        
        solve(root->left , leftSum);
        solve(root->right , leftSum);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        int leftSum = 0;
        solve(root , leftSum);
        return leftSum;
    }
};
