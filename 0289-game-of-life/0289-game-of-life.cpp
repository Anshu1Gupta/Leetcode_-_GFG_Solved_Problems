class Solution {
public:
    vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{1,1},{1,-1},{-1,1}};
    int countLiveCells(vector<vector<int>>&board,int i,int j){
        int count=0;
       for(auto it:dir){
           int nx=i+it.first;
           int ny=j+it.second;
           if(nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size()&&board[nx][ny]==1){
               count++;
           }
       }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>ans=board;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             int count=countLiveCells(board,i,j);
                
             if(board[i][j]==1){
                 if(count<2||count>3)ans[i][j]=0;
             }
             else{
                 if(count==3)ans[i][j]=1;
             }
                
            }
        }
        board=ans;
    }
};