//https://leetcode.com/problems/path-with-maximum-gold/
class Solution {
public:
    
    void solve(vector<vector<int>>& grid ,vector<vector<int>>& visited ,int x , int y , int currSum , int &maxSum){
        
        int n = grid.size() , m = grid[0].size() ;
        if(x<0 || x>=n || y<0 || y>=m)
            return;

        if(grid[x][y] && !visited[x][y]){
             visited[x][y] = 1;
             currSum += grid[x][y];
             maxSum = max(maxSum , currSum);
             solve(grid , visited , x-1, y, currSum , maxSum); 
             solve(grid , visited , x, y+1, currSum , maxSum); 
             solve(grid , visited , x+1, y, currSum , maxSum); 
             solve(grid , visited , x, y-1, currSum , maxSum); 
             currSum -= grid[x][y];
             visited[x][y] = 0;
        }                    
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size() , currSum = 0 , maxSum = 0;
        vector<vector<int>> visited(n , vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(grid , visited , i, j, currSum , maxSum); 
            }
        }
        return maxSum;
    }
};
