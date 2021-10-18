//https://leetcode.com/problems/cousins-in-binary-tree/

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
    
    TreeNode *xparent = NULL , *yparent = NULL;
    int xdepth  = -1 , ydepth = -2 ;
    void solve(TreeNode* root , int x , int y , int currDepth , TreeNode* parent){
        
        if(!root)return ;
        
        if(root->val == x){
            xparent = parent ;
            xdepth = currDepth;
        }
        if(root->val == y){
            yparent = parent;
            ydepth = currDepth;
        }
        
        else{
            solve(root->left , x  , y , currDepth + 1,  root);
            solve(root->right , x , y , currDepth + 1 , root);
        }
           
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        solve(root , x ,y , 0, root);
        return xparent!=yparent && xdepth == ydepth;
 
    }
};
