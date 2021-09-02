// Unique Binary Search Trees II
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
    vector<TreeNode*> solve(int l ,int r){
        
        if(l>r)
            return {NULL};
        
        vector<TreeNode*> ans;
        for(int idx = l ; idx <=r ; idx++){
            vector<TreeNode*> leftSubTrees = solve(l , idx - 1);
            vector<TreeNode*> rightSubTrees = solve(idx + 1 , r);
            for(auto leftSubTree : leftSubTrees){
                for(auto rightSubTree : rightSubTrees){
                    TreeNode* newNode = new TreeNode(idx);
                    newNode -> left = leftSubTree;
                    newNode ->right = rightSubTree;
                    ans.push_back(newNode);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
