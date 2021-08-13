//Set Matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size() , m = matrix[0].size() , firstRowZero = 0 , firstColZero  = 0;
        for(int i=0;i<n;i++)
            if(matrix[i][0]==0)
                firstColZero  = 1;
        
        for(int j=0;j<m;j++)
            if(matrix[0][j]==0)
                firstRowZero  = 1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                    
            }
        }
        
        for(int i=1;i<n;i++){
            if(matrix[i][0])continue;
            for(int j=1;j<m;j++){
                matrix[i][j] = 0;
            }
        }
        for(int j=1;j<m;j++){
            if(matrix[0][j])continue;
            for(int i=1;i<n;i++){
                matrix[i][j] = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            if(!firstColZero)break;
            matrix[i][0] = 0;
        }
        
       for(int j=0;j<m;j++){
            if(!firstRowZero)break;
            matrix[0][j] = 0;
        }
        
    }
};
