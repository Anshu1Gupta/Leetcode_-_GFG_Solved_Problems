class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int,int>>q;
      vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
        int n=grid.size();
        int m=grid[0].size();
        
        
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        int time=0;
        while(!q.empty()){
            
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto it:dir){
                    int nx=x+it.first;
                    int ny=y+it.second;
                    
                    if(nx>=0 && ny>=0 &&nx<n &&ny<m && grid[nx][ny]==1){
                        fresh--;
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                    }
                }
            }
          time++;
            
        }
        
        if(fresh!=0)return -1;
        
        return time-1;
    }
};