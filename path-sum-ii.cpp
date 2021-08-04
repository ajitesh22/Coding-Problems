//https://leetcode.com/problems/path-sum-ii/
class Solution {
public:
    void pathSumUtil(TreeNode* root,int sum,vector<int>curr_path,vector<vector<int>>&result){
        
        if(root==NULL)
            return ;
        
        curr_path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum-root->val==0)
                result.push_back(curr_path);
            //curr_path.pop_back();
        }
        
        
        pathSumUtil(root->left,sum-root->val,curr_path,result);
        pathSumUtil(root->right,sum-root->val,curr_path,result);
       // curr_path.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>>result;
        vector<int>curr_path;
        if(root==NULL)
            return result;
        pathSumUtil(root,sum,curr_path,result);
        return result;  
    }
};
