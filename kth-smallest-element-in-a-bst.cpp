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
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
    void solve(TreeNode* root , int &k , int &ans){
        
        if(!root)
            return ;    
        
        solve(root->left , k , ans);
        k--;
        if(k==0)
            ans = root->val;
        solve(root->right , k ,  ans);       
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int ans = -1;
        solve(root , k , ans);
        return ans;
    }
};

/*

For each node
    return count of nodes in left subtree
    pass  1(current node) + count of leftSubtree  to rightSubtree call




*/
