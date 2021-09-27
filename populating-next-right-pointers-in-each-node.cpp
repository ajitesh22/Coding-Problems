/*https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* getImmediateRightNode(Node* root){
        while(root!=NULL){
            if(root->left!=NULL)
                return root->left;
            if(root->right!=NULL)
                return root->right;
        }
        return root;
    }
    
    void connectNodesOnSameLevel(Node* root){
        
        if(root==NULL)
            return;
        if(root->left!=NULL){
            if(root->right!=NULL){
                root->left->next = root->right;
            }
            else{
                Node* nodeToConnect = getImmediateRightNode(root->next);
                root->left->next = nodeToConnect;
                
            }
        }
        if(root->right!=NULL){
                Node* nodeToConnect = getImmediateRightNode(root->next);
                root->right->next = nodeToConnect;
        }
        connectNodesOnSameLevel(root->right);
        connectNodesOnSameLevel(root->left);
        
    }
    
    Node* connect(Node* root) {
        
        if(root==NULL)
            return root;
        root->next = NULL;
        connectNodesOnSameLevel(root);
        return root;
         
    }
};
