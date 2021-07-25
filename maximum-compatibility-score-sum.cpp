//https://leetcode.com/problems/maximum-compatibility-score-sum/
class Solution {
public:
    
    
    
    int dp[10][10];
    int getScore(vector<int> student , vector<int> mentor , int i , int j){
        if(dp[i][j]!=-1)
            return dp[i][j];
        int cnt =0 ;
        for(int i=0;i<student.size();i++){
            if(student[i]==mentor[i])
                cnt++;
        }
        return dp[i][j] = cnt;
    }
    
    void solve(vector<vector<int>>& students , vector<vector<int>>& mentors ,int idx , int mask , int &maxScore , int currScore){
        
        int n = students.size();
        if(idx==n){
            maxScore = max(maxScore , currScore);
            return ;
        }
        
        
        int score = 0;
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))){
                 solve(students , mentors , idx + 1 , mask | (1<<i) ,maxScore , currScore + getScore(students[idx] , mentors[i] , idx , i));
            }   
        }
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int maxScore = 0;
        memset(dp , -1 , sizeof(dp[0])*10);
        
        solve(students , mentors , 0 , 0 , maxScore,0);
        return maxScore;
    }
};
