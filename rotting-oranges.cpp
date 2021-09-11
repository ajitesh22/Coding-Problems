//https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size() , count = 0;
        queue<pair<pair<int,int> , int>>queue;
        vector<vector<int>> visited( n , vector<int>(m , 0));
        int xDirection[4] = {0 , 0 , 1 , -1 };
        int yDirection[4] = {1 , -1 , 0 , 0 };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    queue.push({{i,j},0});
                    visited[i][j] = 1;
                }
                if(grid[i][j]==2 || grid[i][j]==1)
                    count++;
            }   
        }
        
        int minDays = 0;
        
        while(!queue.empty()){
            auto frontData = queue.front();
            int x = frontData.first.first;
            int y = frontData.first.second;
            int weight = frontData.second;
            queue.pop();
            minDays = max(minDays , weight);
            count--;
            for(int i=0;i<4;i++){
                int newX = x + xDirection[i];
                int newY = y + yDirection[i];
                
                if(newX<0 || newX>=n || newY<0 || newY>=m || visited[newX][newY] || grid[newX][newY]==0)
                    continue;
                queue.push({{newX , newY} , weight + 1});
                visited[newX][newY] = 1;
                 
            }
        }
        if(count>0)
            return -1;
        return minDays;
        
    }
};
