//https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        int n = heights.size() , maxRect = 0;
        stack<int>st;
        
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int lRange = 0 , rRange = i -1 ;
                int currHeight = heights[st.top()];
                st.pop();
                if(!st.empty())
                    lRange = st.top() + 1;
                
                maxRect = max(maxRect , currHeight*(rRange - lRange + 1));
                }
            st.push(i);
                
            }
        
        while(!st.empty()){
            int lRange = 0 , rRange = n - 1 ;
            int currHeight = heights[st.top()];
            st.pop();
            if(!st.empty())
                lRange = st.top() + 1;
            maxRect = max(maxRect , currHeight*(rRange - lRange + 1));
        }
        
        return maxRect;
    }
};
