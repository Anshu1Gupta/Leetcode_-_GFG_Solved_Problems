//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    int n;
    void util(vector<vector<int>> &adj,vector<vector<int>> &res, int j, int i){
        
        res[i][j] = 1;
        
        for(int it = 0; it < adj[j].size(); it++){
            
            if(adj[j][it]==1 && res[i][it]==0) {
                util(adj, res, it, i);
            }
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> arr)
    {
        n = N;
        
        vector<vector<int>> res(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            util(arr, res, i, i);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends