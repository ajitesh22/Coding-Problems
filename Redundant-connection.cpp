//https://leetcode.com/problems/redundant-connection/
class Solution {
public:
    
    
    
    int findParent(int i , vector<int> &parent){
        
        if(parent[parent[i]]!=parent[i]){
            parent[i] = findParent(parent[i] ,parent);
        }
        return parent[i] ;
    }
    
    int  unionNodes(int A ,int B ,vector<int> &parent , vector<int> &componentSize){
        
        int parentOfA = findParent(A,parent);
        int parentOfB = findParent(B,parent);
        if(parentOfA == parentOfB) return 1;
        if(componentSize[parentOfA]>=componentSize[parentOfB])
            swap(parentOfA,parentOfB);
        
        componentSize[parentOfB] += componentSize[parentOfA];
        parent[parentOfA] = parentOfB;
        
        return 0;
        
    }
    
    void initDSU(vector<int> &parent , vector<int> &componentSize){
        
        int n = parent.size();
        for(int i=0;i<n;i++){
            parent[i] = i;
            componentSize[i] = 1; 
        }
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        
         int n = edges.size(); 
         
         vector<int> parent(n+1,0) ;
         vector<int> componentSize(n+1,0);
        
       int x ,y ;
        initDSU(parent , componentSize);
        for(int i=0;i<n;i++){
            int u = edges[i][0] , v =  edges[i][1];
            
             int isCycle = unionNodes(u, v , parent , componentSize);
             if(isCycle){
                x=u;y=v;
             }
            
        }
        
        return {x,y};
        
    }

};
