https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int left = 0 , right = n-1 , ans = 0;
        
        while(left < right){
            int water =  0;
            water = (right - left) * min(height[left] , height[right]);
            ans = max(ans , water);
            if(height[left]<height[right])
                left++;
            else 
                right--;
            
        }
        return ans;
    }
};
