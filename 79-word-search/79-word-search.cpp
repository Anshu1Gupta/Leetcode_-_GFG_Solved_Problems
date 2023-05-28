class Solution {
public:
    vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
    int findWord(int i,int j,vector<vector<char>>& board, string word,int idx){
        if(idx>=word.length()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[idx])return false;
        
        char store=board[i][j];
        board[i][j]='$';
        for(auto it:dir){
            int x=i+it.first;
            int y=j+it.second;
            if(findWord(x,y,board,word,idx+1))return true;
        }
        board[i][j]=store;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        if(m*n<word.length()){
            return false;
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]&&findWord(i,j,board,word,0))return true;
            }
        }
        return false;
    }
};