//https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
class Solution {
public:

    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        // 0-1 BFS solution
        deque<pair<pair<int,int>,int>> dequeue;
        vector<vector<int>> visited( n , vector<int>(m , 0));
        dequeue.push_front({{0,0} , 0});
        int minCost = INT_MAX;
        int xDirection[4] = {0 , 0 , 1 , -1 };
        int yDirection[4] = {1 , -1 , 0 , 0 };
        while(!dequeue.empty()){
            auto frontData = dequeue.front();
            dequeue.pop_front();
            int x = frontData.first.first ;
            int y = frontData.first.second;
            int weight = frontData.second;
            
            if(x==n-1 && y==m-1)
                minCost = min(minCost , weight);
            
            for(int i=0;i<4;i++){
                int newX = x + xDirection[i];
                int newY = y + yDirection[i];
                
                if(newX<0 || newX>=n || newY<0 || newY>=m || visited[newX][newY])
                    continue;
                if(grid[x][y] == (i+1))
                    dequeue.push_front({{newX , newY} , weight});
                else
                    dequeue.push_back({{newX , newY} , weight + 1});
                 
            }
            visited[x][y] = 1;
        }
        
        return minCost; 
    }
};
