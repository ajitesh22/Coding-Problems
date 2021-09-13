//https://leetcode.com/problems/word-search/
class Solution {
public:
    
    bool isWordPresentInMatrix(vector<vector<char>>& board , vector<vector<int>>& visited, string word , int x ,int y , int idx){
        
        int n = board.size() , m = board[0].size();
        if(idx==word.size())
            return true;
        
        if(x<0 || x>=n || y<0 || y>=m || visited[x][y] || board[x][y] != word[idx])
            return false;
        
        int xDirection[4] = { -1 , 0  ,  1  , 0};
        int yDirection[4] = { 0  , 1  ,  0  , -1};
        bool result = false;
        
        for(int i=0;i<4;i++){
            visited[x][y] = 1;
            result |= isWordPresentInMatrix(board , visited , word , x+xDirection[i] , y + yDirection[i], idx+1);
            visited[x][y] = 0;
        }
        return result;  
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size() , m= board[0].size();
        bool result = false;
        vector<vector<int>> visited(n , vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result |= isWordPresentInMatrix(board , visited , word , i , j ,0);
            }
        }
        return result;
    }
};

// 4*3*3*...n  = 4*3^(wordsize - 1) * (rows*column) ~ 4* 3^15 *6 *6
