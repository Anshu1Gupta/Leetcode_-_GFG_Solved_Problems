class Solution {
public:
    bool canPlace(char key,int x,int y,vector<vector<char>>&board){
        
        for(int i=0;i<9;i++){
            if(board[x][i]==key)return false;
            if(board[i][y]==key)return false;
              if(board[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3] == key)
      return false;
        }
        return true;
       
        
        
    }
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k='1';k<='9';k++){
                        if(canPlace(k,i,j,board)){
                            board[i][j]=k;
                            if(solve(board))return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
       return true; 
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};