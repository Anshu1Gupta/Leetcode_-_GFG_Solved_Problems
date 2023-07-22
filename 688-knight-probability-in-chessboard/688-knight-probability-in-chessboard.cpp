class Solution {
public:
    vector<pair<int,int>>dir{{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    unordered_map<string,double>dp;
    double rec(int x,int y,int row,int col,int moves){
        if(x>=row||y>=col||x<0||y<0)
            return false;
        if(moves==0)
            return true;
    
        string rem=to_string(x)+"anshu"+to_string(y)+"gupta"+to_string(moves);
        if(dp.find(rem)!=dp.end())return dp[rem];
        
        double probability=0;
        for(auto it:dir){
            int nx=x+it.first;
            int ny=y+it.second;
            probability+=(rec(nx,ny,row,col,moves-1))/(8.0);
          }

        dp[rem]=probability;
        return dp[rem];
}
    double knightProbability(int n, int k, int row, int column) {
       return rec(row,column,n,n,k);
    }
};