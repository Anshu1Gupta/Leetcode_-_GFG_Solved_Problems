class Solution {
public:
  
bool canPlace(int r,int c,vector<string>&board,int n){

    int dumr=r;
    int dumc=c;

    while(r>=0&&c>=0){
        if(board[r][c]=='Q')return false;
        r--,c--;
    }
    r=dumr,c=dumc;
    while(c>=0){
        if(board[r][c]=='Q')return false;
        c--;
    }
    r=dumr,c=dumc;
    while(r<n&&c>=0){
        if(board[r][c]=='Q')return false;
        r++,c--;
    }
    return true;

}
void nQueens(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(canPlace(row,col,board,n)){
            board[row][col]='Q';
            nQueens(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
    return;
}
    vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>>ans;
    vector<string>temp(n);
    string str(n,'.');
    for(int i=0;i<n;i++){
        temp[i]=str;
    }

    nQueens(0,temp,ans,n);
    return ans;
    }
};