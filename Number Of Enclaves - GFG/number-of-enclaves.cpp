//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

  
int bfs(int sr,int sc, vector<vector<int>>&visited,vector<vector<int>>& grid){
    queue<pair<int,int>>q;
     int n=grid.size();
        int m=grid[0].size();
    q.push({sr,sc});
     int flag=0;
  int count=0;
    vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
    while(!q.empty()){
        count++;
        int row=q.front().first;
        int column=q.front().second;
          visited[row][column]=1;
        // count++;
        q.pop();
      
        if(row==n-1||row==0||column==0||column==m-1){
                    flag=1;
                }
        for(auto it:dir){
            int nr=row+it.first;
            int nc=column+it.second;
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&!visited[nr][nc]&&grid[nr][nc]==1){
                if(nr==n-1||nr==0||nc==0||nc==m-1){
                    flag=1;
                }
                visited[nr][nc]=1;
                q.push({nr,nc});
            }
        }


    }
      if(flag==1){
          return -1;
      }
      if(count==0)return 1;
    return count;
    
}

        int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&grid[i][j]==1){
             int x=bfs(i,j,visited,grid);
             if( x!=-1){
                sum=sum+x;
             }
                }
            }
        }
    
        return sum;
        
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends