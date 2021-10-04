//https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    void preOrderRecursion(TreeNode* root , vector<int> &result){
        if(root==NULL)
            return;
        
        result.push_back(root->val);
        preOrderRecursion(root->left , result);
        preOrderRecursion(root->right ,result);     
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>result;
        if(!root)
            return result;
        
        stack<TreeNode*>stack;
        stack.push(root);
        
        while(!stack.empty()){
            auto topElement = stack.top();
            stack.pop();
            result.push_back(topElement->val);
            if(topElement->right!=NULL)
                stack.push(topElement->right);
            if(topElement->left!=NULL)
                stack.push(topElement->left);
        }
        
        return result;
        
        /*
        vector<int> result;
        preOrderRecursion(root, result);
        return result;
        */
    }
};
