 //https://www.lintcode.com/problem/915
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
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */

    TreeNode * findMinNodeInRightSubTree(TreeNode * root){
        if(root->left==NULL)
            return root;
        else
            return findMinNodeInRightSubTree(root->left);
    } 
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {

        if(root==NULL || p==NULL)
            return NULL;

        if(p->right!=NULL){
            TreeNode* temp  = findMinNodeInRightSubTree(p->right);
            return temp;
        }
        TreeNode* temp = root , *ans = NULL;
        while(temp->val!=p->val){
            if(temp->val > p->val){
                ans = temp;
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return ans;
    }
};

/*


            4
          3   5 
        1  2 





*/










