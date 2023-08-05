class Solution {
public:
    bool canPlace(int x,int y, vector<string>&temp,int n){
        
        int nx=x;
        int ny=y;
        
        while(x>=0&&y>=0){
            if(temp[x][y]=='Q')return false;
            x--,y--;
        }
        x=nx,y=ny;
        while(x<n&&y>=0){
            if(temp[x][y]=='Q')return false;
            x++;y--;
        }
        
        x=nx,y=ny;
        while(y>=0){
            if(temp[x][y]=='Q')return false;
            y--;
        }
        return true;
        
      
    }
    void findAll(int col,int n,string &str,vector<string>&temp,vector<vector<string>>&ans){
       
        if(col>=n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(canPlace(row,col,temp,n)){
                temp[row][col]='Q';
                findAll(col+1,n,str,temp,ans);
                temp[row][col]='.';
            }
        }
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        vector<string>temp(n,str);
        
        vector<vector<string>>ans;
        
        findAll(0,n,str,temp,ans);
        return ans;
    }
};