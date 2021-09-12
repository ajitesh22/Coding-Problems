#define mod 1000000007
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        
        int n = nums.size();
        long long int ps[n+1],left[n+1],right[n+1];
        
        
        ps[0]=nums[0];
        for(int i=1;i<n;i++)
            ps[i]=(nums[i]+ps[i-1]);
        
        stack<int>st;
        st.push(0);
        
        for(int i=1;i<n;i++){
            int curr = nums[i];
            if(!st.empty() && nums[st.top()]<=nums[i]){
                st.push(i);
            }
            else if (!st.empty() && nums[st.top()]>nums[i]){
                
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    int idx = st.top();st.pop();
                    if(!st.empty())
                        left[idx] = st.top()+1;
                    else 
                        left[idx] = 0;
                    
                    right[idx] = i-1;
                }
                st.push(i);
            }
        }
        
        
        int rlimit = n-1;
        while(!st.empty()){
            int idx = st.top();st.pop();
            right[idx] = rlimit;
            if(!st.empty())
                left[idx] = st.top()+1;
            else 
                left[idx] = 0;
        }
        
        
         long long int maxprod = 0;
        
        for(int i=0;i<n;i++){
            long long int v = 0;
            if(left[i]-1>=0)
                v=ps[left[i]-1];
            long long int s = (ps[right[i]] - v);
            maxprod = max(maxprod , ((s*nums[i])));
            
        }
        return (int)(maxprod%mod); 
    }
};
