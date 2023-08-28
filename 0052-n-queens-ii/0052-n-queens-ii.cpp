class Solution {
public:
    bool canPlace(int row,int col,vector<string>&mat){
        
        int x=row;
        int y=col;
        
        while(x>=0&&y>=0){
            if(mat[x][y]=='|')return false;
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x<mat.size()&&y>=0){
            if(mat[x][y]=='|')return false;
            x++;
            y--;
        }
         x=row;
        y=col;
        while(x>=0&&y<mat[0].size()){
            if(mat[x][y]=='|')return false;
            x--;
            y++;
        }
        x=row;
        y=col;
        while(x<mat.size()&&y<mat[0].size()){
            if(mat[x][y]=='|')return false;
            x++;
            y++;
        }
        
        x=row;
        y=col;
        while(x>=0){
            if(mat[x][y]=='|')return false;
            x--;
        }
        return true;
    }
    void perm(int row,vector<string>&mat,vector<vector<string>>&ans,int n){
        if(row>=n){
            ans.push_back(mat);
            return;
        }
        for(int col=0;col<n;col++){
            if(canPlace(row,col,mat)){
                mat[row][col]='|';
                perm(row+1,mat,ans,n);
                mat[row][col]='.';
            }
        }
         return;
    }
    int totalNQueens(int n) {
        
        string str(n,'.');
        vector<string>temp(n,str);
        vector<vector<string>>ans;
        
        perm(0,temp,ans,n);
        return ans.size();
    }
};