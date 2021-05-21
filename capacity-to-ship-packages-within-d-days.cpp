//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days
class Solution {
public:
    
    int checkIfPossible(vector<int>& weights , int days , int maxCapacity){
        
        int   currCapacity = 0;
        
        for(int i=0;i<weights.size();i++){
            
            currCapacity += weights[i];
            if(currCapacity > maxCapacity){
                days--;
                currCapacity = weights[i];
            }
        }
        
        if(days<=0 || currCapacity > maxCapacity)
            return 0;
        return 1;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size() ,weightSum = 0 , maxElement = 0;
        for(int weight : weights){
            weightSum += weight;
            maxElement = max(maxElement , weight);
        }
        
        // binary search : search space : [1 , sum(weights)]
        
        int low = maxElement, high = weightSum ;
        
        while(low<high){
            
            int mid =  low + (high - low)/2;
            if(checkIfPossible(weights , days , mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
            
        }
        return high; 
    }
};
