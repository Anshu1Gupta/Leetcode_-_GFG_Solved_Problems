class Solution {
public:
    vector<pair<int,int>>dir{{-1,0},{0,-1},{0,1},{1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         queue<pair<int,int>>q;
         for(int i=0;i<mat.size();i++){
             for(int j=0;j<mat[0].size();j++){
                 if(mat[i][j]==0){
                     q.push({i,j});
                 }
             }
         }
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        while(!q.empty()){
            int s=q.size();
            count++;
            
            while(s--){
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                for(auto it:dir){
                    int nx=x+it.first;
                    int ny=y+it.second;
                    
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&mat[nx][ny]==1&&!visited[nx][ny]){
                        mat[nx][ny]=count;
                        visited[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return mat;
        
    }
};