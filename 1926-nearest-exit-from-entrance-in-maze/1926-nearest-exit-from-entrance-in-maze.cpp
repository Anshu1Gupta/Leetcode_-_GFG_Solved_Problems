class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int i=entrance[0];
        int j=entrance[1];
        
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir{{-1,0},{0,-1},{0,1},{1,0}};
        q.push({i,j});
        grid[i][j]='+';
        
        int count=1;
        while(!q.empty()){
            
            int s=q.size();
            while(s--){
                int x=q.front().first;
                int y=q.front().second;q.pop();
                
                for(auto it:dir){
                    int nx=x+it.first;
                    int ny=y+it.second;
                    
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]=='.'){
                        if((nx==0||ny==0||nx==n-1||ny==m-1))return count;
                        grid[nx][ny]='+';
                        q.push({nx,ny});
                        
                    }
                }
            }
            count++;
        }
        return -1;
    }
};