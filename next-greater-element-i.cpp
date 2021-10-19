//https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        unordered_map<int,int>ans;
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            
            while(!st.empty()){
                if(nums2[st.top()]<nums2[i]){
                    ans[nums2[st.top()]] = nums2[i];
                    st.pop();
                }
                else{
                    
                    break;
                }
                st.push(i);
            }
        }
        int top ;
        if(!st.empty()){
             top = nums2[st.top()];
            st.pop();
            
        }
        
        while(!st.empty()){
            ans[nums2[st.top()]] = top;
            st.pop();
        }
       /* 
        for(auto v : ans){
            cout<<v.first<<" "<<v.second<<" ";
        }
        */
        
        vector<int>result;
        for(int num : nums1){
            if(ans.count(num))
                result.push_back(ans[num]);
            else
                result.push_back(-1);
        }
        
        return result;
        
    }
};
