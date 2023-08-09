class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        if(fresh==0)return 0;
        if(q.empty()&&fresh!=0)return -1;
        
        int count=1;
        while(!q.empty()){
            int s=q.size();
            
            while(s--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto it:dir){
                    int nx=x+it.first;
                    int ny=y+it.second;
                    
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==1){
                        fresh--;
                        if(fresh==0)return count;
                        
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        
                    }
                }
            }
            count++;
        }
        return -1;
        
    }
};