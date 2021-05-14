class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size() - 1 , ans = 1;
        cout<<n<<endl;
        int maxColor[n+1][27];
        
        vector<int> adj[n+1];
        vector<int> inDegree(n+1,0);
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=26;j++)
                maxColor[i][j] = 0;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0] , v = edges[i][1];
            if(u==v)return -1;
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int>queue; 
        for(int i=0;i<=n;i++){
            if(inDegree[i]==0){
                queue.push(i);
            }
        }
        int seen = 0;
        while(!queue.empty()){
            
            int currNode = queue.front();
            cout<<currNode<<endl;
            queue.pop();
            seen++;
            maxColor[currNode][colors[currNode] - 'a']++;
            for(int i=0;i<26;i++)
                ans = max(ans , maxColor[currNode][i]);
            
            for(int neighbor : adj[currNode]){
                cout<<currNode<<":"<<neighbor<<",";
                for(int i=0;i<26;i++){
                    maxColor[neighbor][i] = max(maxColor[neighbor][i] , maxColor[currNode][i]);               
                }
                
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0){
                    queue.push(neighbor);cout<<"enter"<<" "<<neighbor<<",";
                }        
           }      
       }
        return (seen == n+1) ? ans : -1;   
        
    }
};
