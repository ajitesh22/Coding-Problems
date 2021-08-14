//remove boxes
class Solution {
public:
    int dp[101][101][101];
    int getMaxScoreUtil(vector<int>& boxes , int start , int end , int streak){
        
        if(start==end)
            return (streak+1)*(streak+1);
        
        if(start>end)
            return 0;
        
        if(dp[start][end][streak]!=-1)
            return  dp[start][end][streak] ;
        
        int maxScore = getMaxScoreUtil(boxes , start + 1 , end , 0) +  (streak+1)*(streak+1);
        for(int i=start + 1  ; i<=end ; i++){
            if(boxes[start]==boxes[i])
                maxScore = max(maxScore ,
                               getMaxScoreUtil(boxes , start + 1 , i - 1 , 0) + 
                               getMaxScoreUtil(boxes , i + 1 , end, streak+1));
        }

        return dp[start][end][streak] = maxScore;  
    }
    
    
    
    int removeBoxes(vector<int>& boxes) {
        
        memset(dp , -1 , sizeof(dp[0])*100*100);
        
        if(boxes.size()==0)
            return 0;
        int n = boxes.size();
        return getMaxScoreUtil(boxes, 0 , n -1 , 0);
        
    }
};


/*

[1,3,2,2,2,3,4,3,1]


                dp[0][0] + 4*4 + dp[5][5]
                1 , 2 2 2 2 , 3
           [2 , 3 ]     [1, 3]      [1,2]
        [3]  [2]        [3] [1]      [2] [1]  
        
        2**N 
        
        
        TC  and SC : O(N^2) 








*/
