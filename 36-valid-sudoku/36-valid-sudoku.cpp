class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<string,int>mp;
     
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
              if(board[i][j]=='.')continue;
                string stri="row"+to_string(i)+board[i][j];
                string strc="col"+to_string(j)+board[i][j];
                int blo=i/3*3+j/3;
                string bl="block"+to_string(blo)+board[i][j];
                if(mp.find(stri)!=mp.end()||mp.find(strc)!=mp.end()||mp.find(bl)!=mp.end())return false;
                else{
                    mp[stri]=1;
                    mp[strc]=1;
                    mp[bl]=1;
                    
                }
            }
        }return true;
    }
};