class Solution {
public:
     bool ifValid(int x,int y,int parent,vector<vector<int>>&mat){
                   if(x>=mat.size()||y>=mat[0].size()||x<0||y<0||parent>=mat[x][y])return false;
                   return true;
            }          
	int findMax(int x,int y,int parent,vector<vector<int>>&dp,vector<vector<int>>&mat){
                if(!ifValid(x,y,parent,mat))return 0;
                if(dp[x][y]!=-1)return dp[x][y];
  
                 int top=findMax(x-1,y,mat[x][y],dp,mat);
                 int right=findMax(x,y+1,mat[x][y],dp,mat);
                 int bottom=findMax(x+1,y,mat[x][y],dp,mat);
                 int left=findMax(x,y-1,mat[x][y],dp,mat);
                 return dp[x][y]=1+max(max(top,bottom),max(right,left));

            }
	int longestIncreasingPath(vector<vector<int>>& matrix) {
    	int n=matrix.size();
    	int m=matrix[0].size();
   	 
    	vector<vector<int>>dp(n,vector<int>(m,-1));
    	int maxi=1;
    	for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
            	dp[i][j]=findMax(i,j,-1,dp,matrix);
                	maxi=max(maxi,dp[i][j]);
        	}
    	}
    	return maxi;
	}
};
