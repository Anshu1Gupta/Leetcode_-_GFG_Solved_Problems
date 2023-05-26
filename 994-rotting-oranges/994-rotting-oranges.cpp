
// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int zero=0;
       int two=0;
       vector<vector<int>>visited=grid;
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
           if(visited[i][j]==0){
               zero++;
           }
               if(visited[i][j]==2){
                   two++;
                   q.push({i,j});
               }
           }
       }
       vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
       int result=-1;
       while(!q.empty()){
           int s=q.size();
           while(s--){
               int x=q.front().first;
               int y=q.front().second;
               q.pop();
               for(auto g:dir){
                   int x1=x+g.first;
                   int y1=y+g.second;
                   if( x1>=0&&x1<n&&y1>=0&&y1<m&&visited[x1][y1]==1){
                       two++;
                           visited[x1][y1]=2;
                           q.push({x1,y1});

                   }
               }
              
           }
            result++;
       }
      if(zero==n*m){
          return 0;
      }
      if(zero+two==0)return -1;
       if(zero+two==n*m)
       return result;
       else return -1;
    }
};

// } Driver Code Ends