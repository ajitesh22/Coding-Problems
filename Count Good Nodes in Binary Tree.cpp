//Count Good Nodes in Binary Tree
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
    
    void dfs(TreeNode* root , int &cnt , int maxNodeEncounterSoFar){
        
        if(!root)
            return;
        
        if(root->val>=maxNodeEncounterSoFar)
            cnt++;
        maxNodeEncounterSoFar = max(root->val , maxNodeEncounterSoFar);
        dfs(root -> left , cnt , maxNodeEncounterSoFar);
        dfs(root ->right , cnt , maxNodeEncounterSoFar);
    }
    
    
    int goodNodes(TreeNode* root) {
        
        int cnt = 0;
        dfs(root , cnt , INT_MIN);
        return cnt;
        
        
        
    }
};
