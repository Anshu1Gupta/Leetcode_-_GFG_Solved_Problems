class Solution {
public:
    vector<pair<int,int>>dir{{-1,0},{0,-1},{0,1},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>effort(n,vector<int>(m,1e9));
        queue<pair<int,int>>q;
        q.push({0,0});
        effort[0][0]=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto it:dir){
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int newEffort=abs(heights[nx][ny]-abs(heights[x][y]));
                    int val=max(newEffort,effort[x][y]);
                    
                    if(effort[nx][ny]>val){
                        effort[nx][ny]=val;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return effort[n-1][m-1];
    }
};