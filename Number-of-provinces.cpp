//https://leetcode.com/problems/number-of-provinces/
class Solution {
public:
    
    
    
    int findParent(int i , vector<int> &parent){
        
        if(parent[parent[i]]!=parent[i]){
            parent[i] = findParent(parent[i] ,parent);
        }
        return parent[i] ;
    }
    
    void unionNodes(int A ,int B ,vector<int> &parent , vector<int> &componentSize){
        
        int parentOfA = findParent(A,parent);
        int parentOfB = findParent(B,parent);
        
        if(parentOfA == parentOfB) return ;
        if(componentSize[parentOfA]>=componentSize[parentOfB])
            swap(parentOfA,parentOfB);
        
        componentSize[parentOfB] += componentSize[parentOfA];
        parent[parentOfA] = parentOfB;
        
    }
    
    void initDSU(vector<int> &parent , vector<int> &componentSize){
        
        int n = parent.size();
        for(int i=0;i<n;i++){
            parent[i] = i;
            componentSize[i] = 1; 
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<int> parent(n+1,0) ;
        vector<int> componentSize(n+1,0);
        
        initDSU(parent , componentSize);
        
        
        for(int i=0;i< n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i<j){
                    unionNodes(i+1, j+1, parent , componentSize);
                }
            }
        }
        
        set<int>Set;
        for(int i=1;i<=n;i++){
            Set.insert(findParent(parent[i] , parent));
        }
        
        return Set.size();
        
        
    }
};
