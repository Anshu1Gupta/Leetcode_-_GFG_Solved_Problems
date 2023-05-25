class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
queue<pair<int,int>>q;
        int n=mat.size();
          int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
      
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j]=1;

                }

            }
        }
        
        vector<pair<int,int>>dir{{-1,0},{0,-1},{0,1},{1,0}};
        
        while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
            q.pop();
            for(auto it:dir){
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&!visited[nx][ny]){
                    mat[nx][ny]=mat[x][y]+1;
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
            
        }
        return mat;
        
    }
};