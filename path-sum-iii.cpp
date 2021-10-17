//https://leetcode.com/problems/path-sum-iii/
class Solution {
public:
    
    void pathSumUtil(TreeNode* root,int sum,int curr_sum,unordered_map<int,int>&mp,int &count){
        
        if(root==NULL)
            return;
        curr_sum+=root->val;
        if(mp.find(curr_sum-sum)!=mp.end())
            count+=mp[curr_sum-sum];
        if(mp.find(curr_sum)==mp.end())
            mp.insert({curr_sum,1});
        else
            mp[curr_sum]++;
        
        pathSumUtil(root->left,sum,curr_sum,mp,count);
        pathSumUtil(root->right,sum,curr_sum,mp,count);
        
        mp[curr_sum]--;
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(root==NULL)
            return 0;
        
        int count=0;
        unordered_map<int,int>mp;
        mp.insert({0,1});
        pathSumUtil(root,sum,0,mp,count);
        return count;   
    }
};
