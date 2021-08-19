//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
#define ll long long int
#define max(a,b) (a>=b)?a:b
#define mod 1000000007
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
    
    void dfs1(TreeNode* root , ll &sum){
        
        if(root==NULL)
            return ;
        
        sum += root->val;
        dfs1(root->left , sum);
        dfs1(root->right , sum);
        
    }
    
    ll dfs2(TreeNode* root ,ll currSum ,ll sum ,ll  &maxProd){
        
        if(root==NULL)
            return 0;

        ll lsubtreeSum = dfs2(root->left , lsubtreeSum , sum , maxProd);
        ll rsubtreeSum = dfs2(root->right , rsubtreeSum , sum , maxProd);
        
        if(lsubtreeSum)
            maxProd = max(maxProd , lsubtreeSum * (sum - lsubtreeSum));
        if(rsubtreeSum)
            maxProd = max(maxProd , rsubtreeSum * (sum - rsubtreeSum));
        
        return lsubtreeSum + rsubtreeSum + root->val;
    }
    
    
    int maxProduct(TreeNode* root) {
        
        ll sum = 0 , currSum = 0 , maxProd = 1;
        dfs1(root , sum);
        ll v = dfs2(root ,currSum , sum , maxProd);
        
        return maxProd%mod;
    }
};
