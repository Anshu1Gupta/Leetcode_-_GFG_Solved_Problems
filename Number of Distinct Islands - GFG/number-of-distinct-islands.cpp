//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
        //four directions to travel
    vector<pair<int,int>>dir{{-1,0},{0,-1},{0,1},{1,0}};
        
        
      
    void bfs(int r,int c, vector<vector<int>>&grid,set<vector<pair<int,int>>>&set,vector<vector<int>>&visited){
        visited[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        
        //arranging all the nodes distance relative to the parent node
        vector<pair<int,int>>arrange;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            arrange.push_back({x-r,y-c});
            
            
            //exploring all four nodes
            for(auto it:dir){
                int nx=x+it.first;
                int ny=y+it.second;
                
                if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&!visited[nx][ny]&&grid[nx][ny]==1){
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
            
        }
        
        
        set.insert(arrange);
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row=grid.size();
        int col=grid[0].size();
        
        
        // calling to find islands
        vector<vector<int>>visited(row,vector<int>(col,0));
        set<vector<pair<int,int>>>set;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                    bfs(i,j,grid,set,visited);
                }
            }
        }
        
        //returning unique number of islands
        return set.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends