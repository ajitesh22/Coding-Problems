//https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int n = maze.size() , m = maze[0].size();
        vector<vector<int>> vis(n+1 , vector<int>(m+1 , 0));
        
        queue<vector<int>>queue;
        queue.push({ent[0],ent[1] , 0});
        
        int xdir[4] = {-1 , 0 , 1 , 0};
        int ydir[4] = {0  , 1 , 0 , -1};

        int c = 0;
        while(!queue.empty()){
            
            auto v = queue.front();
            queue.pop();
            int x = v[0] , y = v[1] , d = v[2];
            if(vis[x][y])
                continue;
            
            for(int i=0;i<4;i++){
                int xd = x + xdir[i];
                int yd = y + ydir[i];
                if(xd>=0 && xd<n && yd>=0 && yd<m && maze[xd][yd]=='+')
                    continue;
                
                if(xd==ent[0]  && yd==ent[1])
                    continue;
                
                if(xd>=0 && xd<n && yd>=0 && yd<m && maze[xd][yd]=='.'){
                    if(xd==0 || xd == n-1 || yd==0 || yd == m-1)
                        return d+1;
                    else if(!vis[xd][yd])
                        queue.push({xd ,yd , d+1});
                } 
            }
            vis[x][y] = 1;
        }
        
        return -1;
        
        
    }
};
