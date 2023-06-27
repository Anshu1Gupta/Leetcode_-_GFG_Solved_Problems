class Solution {
public:
    
bool canInsert(vector<vector<char>>& matrix,int i,int j,char val){
    for(int p=0;p<9;p++){
        if(matrix[i][p]==val)return false;
        if(matrix[p][j]==val)return false;
        if(matrix[3 * (i / 3) + p / 3][3 * (j / 3) + p % 3] == val)
      return false;
    }
    return true;
}
    bool solve(vector<vector<char>>&matrix){
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]=='.'){
                for(char k='1';k<='9';k++){
                    if(canInsert(matrix,i,j,k)){
                        matrix[i][j]=k;
                        if(solve(matrix))
                             return true;
                        else
                             matrix[i][j]='.';
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