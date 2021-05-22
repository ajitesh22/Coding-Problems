class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        
        int n = heights.size() ,m = heights[0].size();
        vector<vector<int>> efforts(n , vector<int>(m , INT_MAX));
        
        set<pair<int,pair<int,int>>>pq;
        
        pq.insert({0,{0,0}});
        efforts[0][0] = 0;
        while(!pq.empty()){
            auto it = pq.begin();
            int minEffort = it->first , x = it->second.first , y = it->second.second;
            pq.erase(it);
            
            if(x == n-1 && y == m-1)return minEffort;
            
            int xdir[4] = {-1 , 0  , 1  ,  0 };
            int ydir[4] = { 0 , 1  , 0  , -1 };
            
            for(int i=0;i<4;i++){
                
                int newX = x + xdir[i] , newY = y + ydir[i];
                
                if(newX<0  || newX>=n  ||  newY<0  ||  newY>=m)continue;
                    
                    int currEffort = max(minEffort , abs(heights[x][y] - heights[newX][newY]));
                    
                    if(efforts[newX][newY] > currEffort){
                        pq.insert({currEffort , {newX , newY}});
                        efforts[newX][newY] = currEffort;
                     }
            }
            
        }
        
        return efforts[n-1][m-1];
        
        
    }
};
