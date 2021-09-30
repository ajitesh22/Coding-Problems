//Partition to K Equal Sum Subsets
class Solution {
public:
    
    int checkIfPossibleToPartition(vector<int>& nums , int k , int sum ,int currSum ,int mask ,int idx){
        
        if(currSum>sum)
            return 0;
        cout<<mask<<endl;
        if(idx==nums.size()){
            return 1;
        }
        
        int ans = 0;
        for(int i=0 ;i<nums.size();i++){
            if((mask & (1<<i)))
                continue; 
                currSum +=nums[i];
                if(currSum==sum)
                    ans |= checkIfPossibleToPartition(nums , k-1 , sum , 0 , mask | (1<<i) ,i+1);
                else
                    ans |= checkIfPossibleToPartition(nums , k , sum , currSum , mask | (1<<i),i+1);
        }
        
        return ans;       
               
    }
    
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0 , currSum = 0;
        for(auto num : nums)
            sum+=num;
        if(sum%k)
            return 0;
        
        return checkIfPossibleToPartition(nums , k , sum /k, currSum , 0 ,0);
        
    }
};
