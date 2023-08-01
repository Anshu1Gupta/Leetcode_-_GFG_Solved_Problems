//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
       queue<vector<int>>q;
       if(A[0][0]==0)return -1;
       q.push({0,0,0});
       A[0][0]=0;
       while(!q.empty()){
           int x=q.front()[0];
           int y=q.front()[1];
           int steps=q.front()[2];
           q.pop();
           
           if(x==X&&y==Y)return steps;
           
           for(auto it:dir){
               int nx=x+it.first;
               int ny=y+it.second;
               
               if(nx<N&&nx>=0&&ny<M&&ny>=0&&A[nx][ny]==1){
                   A[nx][ny]=0;
                   q.push({nx,ny,steps+1});
               }
           }
           
           
       }
       return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends