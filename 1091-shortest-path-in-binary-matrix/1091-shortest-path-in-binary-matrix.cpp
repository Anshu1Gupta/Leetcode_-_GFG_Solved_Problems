class Solution {
public:
int bfs(int sr,int sc,vector<vector<int>>& visited,vector<vector<int>>& grid){
    queue<pair<int,int>>q;
     int n=grid.size();
    int m=grid[0].size();
    q.push({sr,sc});
    if(grid[sr][sc]==1)return -1;
    if(sr==n-1&&sc==m-1)return 1;
    // visited[sr][sc]=1;
    vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    int count=1;
    while(!q.empty()){
       count++;
       int s=q.size();
       while(s--){
        int row=q.front().first;
        int column=q.front().second;
        q.pop();
        for(auto it: dir){
            int nr=row+it.first;
            int nc=column+it.second;
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&!visited[nr][nc]&&grid[nr][nc]==0){
                if(nr==n-1&&nc==m-1)return count;
                visited[nr][nc]=1;
                q.push({nr,nc});
            }
        }
       }

    }
    return -1;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        return bfs(0,0,visited,grid);

    }
};