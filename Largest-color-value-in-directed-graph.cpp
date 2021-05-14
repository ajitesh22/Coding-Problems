class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        /*
        
            LEETCODE CONTEST 240 UPSOLVING
        
            idea is to run topological sort . while removing a independant node(nodes having zero incoming edges) check if it can update its neigbor node max color [26] array.
            once Topological sort  ends there should not be any element in the queue . if there are elements return -1 (cycle exists)
            
            DP + TOPOLOGICAL SORT
        
        */
        int n = edges.size() , ans = 1;
        int maxColor[n+1][27];
        
        vector<int> adj[n+1];
        vector<int> inDegree(n+1,0);
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=26;j++)
                maxColor[i][j] = 0;
        
        for(int i=0;i<n;i++){
            int u = edges[i][0] , v = edges[i][1];
            if(u==v)return -1;
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int>queue;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
                queue.push(i);
        }
      
        cout<<queue.size()<<" dddd";
        while(!queue.empty()){
            
            int currNode = queue.front();
            queue.pop();
            
          /*  cout<<currNode<<" ";
            
            cout<<(colors[currNode])<<" ";
             return 0;*/
            //return 0;
            cout<<colors[currNode]<<" ";
            cout<<(int)colors[currNode]<<" ";
           // maxColor[currNode][colors[currNode] - 'a']++; 
            
            for(int i=0;i<26;i++)
                ans = max(ans , maxColor[currNode][i]);
            
            for(int neighbor : adj[currNode]){
                
                
                for(int i=0;i<26;i++){
                   // cout<<colors[i] - 'a'<<" ";
                    maxColor[neighbor][i] = max(maxColor[neighbor][i] , maxColor[currNode][i]);
                }
                
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0)
                    queue.push(neighbor);
                    
           }  
              
       }
            
      //  cout<<" "<<ans<<" ";
                                                                                           
        if(!queue.empty())
            return -1;
        
        return ans;   
        
    }
};
