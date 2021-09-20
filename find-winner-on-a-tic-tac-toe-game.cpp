//https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int grid[3][3] ;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                grid[i][j] = -1;
            }
        }
        int turn = 0 ;
        for(auto move : moves){
            int x = move[0] , y = move[1];
            grid[x][y] = turn;
            turn = !turn;
        }
        
        for(int i=0;i<3;i++){
            if((grid[i][0] == 0 && grid[i][1] == 0 && grid[i][2] == 0 )|| (grid[0][i] == 0 && grid[1][i] == 0 && grid[2][i] == 0 )){
                return "A";
            }
            if((grid[i][0] == 1 && grid[i][1] == 1 && grid[i][2] == 1 )|| (grid[0][i] == 1 && grid[1][i] == 1 && grid[2][i] == 1 )){
                return "B";
            }
        }
        
        if((grid[0][0] == 0 && grid[1][1] == 0 && grid[2][2] == 0) || (grid[0][2] == 0 && grid[1][1] == 0 && grid[2][0] == 0) )
           return "A";
        
                if((grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) || (grid[0][2] == 1 && grid[1][1] == 1 && grid[2][0] == 1) )
           return "B";
           
        if(moves.size()==9)
            return "Draw";
        
        return "Pending";
        
    }
};
