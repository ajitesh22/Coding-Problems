https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        auto ptr = preorder.begin();
        TreeNode* root = new TreeNode(*ptr);
        st.push(root);
        while(++ptr != preorder.end()) {
            if (*ptr < st.top()->val) {
                auto left = new TreeNode(*ptr);
                st.top()->left = left;
                st.push(left);
            }
            else {
                auto curr = st.top(); st.pop();
                while(!st.empty() && st.top()->val < *ptr) {
                    curr = st.top(); st.pop();
                }
            
                auto right = new TreeNode(*ptr);
                curr->right = right;
                st.push(right);
            }
        }
        
        return root;
    }
};


/*

                l 
    preorder : [8,5,1,7,10,12]
    
                      l
    inorder  : [1,5,7,8,10,12]
    
    
    




*/
