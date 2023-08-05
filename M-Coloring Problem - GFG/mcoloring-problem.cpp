//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool canPos(int node,vector<int>adj[],vector<int>&color,int col){
        for(auto it:adj[node]){
            if(color[it]==col)return false;
        }
        return true;
    }
    bool canColor(int node,vector<int>adj[],vector<int>&color,int m,int n){
        if(node==n){
            return true;
        }
        
        for(int i=1;i<=m;i++){
            if(canPos(node,adj,color,i)){
                color[node]=i;
                if(canColor(node+1,adj,color,m,n))return true;
                color[node]=-1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>adj[102];
        vector<int>color(102,-1);
        
        for(int i=0;i<102;i++){
            for(int j=0;j<102;j++){
                if(graph[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        return canColor(0,adj,color,m,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends