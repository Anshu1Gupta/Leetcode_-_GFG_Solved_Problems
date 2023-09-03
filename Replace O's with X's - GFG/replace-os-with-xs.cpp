//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   vector<pair<int,int>>dir{{-1,0},{0,-1},{0,1},{1,0}};
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O')q.push({i,0});
            if(mat[i][m-1]=='O')q.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O')q.push({0,i});
            if(mat[n-1][i]=='O')q.push({n-1,i});
        }
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            mat[x][y]='-';
            
            
            for(auto it:dir){
                int nx=x+it.first;
                int ny=y+it.second;
                
                if(nx<n&&nx>=0&&ny<m&&ny>=0&&mat[nx][ny]=='O'){
                    mat[nx][ny]='-';
                    q.push({nx,ny});
                }
            }
        }
        
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='-')mat[i][j]='O';
                else if(mat[i][j]=='O')mat[i][j]='X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends