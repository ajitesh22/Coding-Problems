//https://leetcode.com/problems/3sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>>ans;
        if(nums.size()<3)return ans;
        sort(nums.begin(),nums.end());
        set<string>s;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)k++;
        }
        if(k==nums.size())
                return {{0,0,0}};
        for(int index=0;index<nums.size()-2;index++){
            
            int leftptr=index+1,rightptr=nums.size()-1;
            
            while(leftptr<rightptr){
                if(nums[leftptr]+nums[rightptr]+nums[index]==0){
                    string key=to_string(nums[index])+":"+to_string(nums[leftptr])+":"+to_string(nums[rightptr]);
                    if(s.find(key)==s.end()){
                        s.insert(key);
                        ans.push_back({nums[index],nums[leftptr],nums[rightptr]});
                    }
                    leftptr++;
                    rightptr--;      
                }
                
                else if(nums[leftptr]+nums[rightptr]+nums[index]>0)
                    rightptr--;
                
                else if(nums[leftptr]+nums[rightptr]+nums[index]<0)
                    leftptr++;
            }            
        }
        
        return ans;
        
        
    }
};
