class Solution {
public:
void bfs(int sr,int sc, vector<vector<int>>&visited,vector<vector<char>>& grid){
    queue<pair<int,int>>q;
     int n=grid.size();
        int m=grid[0].size();
    q.push({sr,sc});
    vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
    while(!q.empty()){
        int row=q.front().first;
        int column=q.front().second;
        q.pop();
        for(auto it:dir){
            int nr=row+it.first;
            int nc=column+it.second;
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&!visited[nr][nc]&&grid[nr][nc]=='1'){
                visited[nr][nc]=1;
                q.push({nr,nc});
            }
        }


    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&grid[i][j]=='1'){
                    island++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return island;
        
    }
};