//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution{
// public:

//     bool isPlace (int source,vector<int>adj[],vector<int>&coloured,int col){
//         for(auto it:adj[source]){
//             if(coloured[it]==col)return false;
//         }
//         return true;
//     }
//     bool canColour(int source,vector<int>adj[],vector<int>&coloured,int m,int n ){
//         if(source==n)return true;
//         for(int i=1;i<=m;i++){
//             if(isPlace(source,adj,coloured,i)==true){
//                 coloured[source]=i;
//                 if(canColour(source+1,adj,coloured,m,n))return true;
//                 else coloured[source]=-1;
//             }
//         }
//     }
//     bool graphColoring(bool graph[101][101], int m, int n) {
//         vector<int>adj[102];
//         vector<int>coloured(102,-1);
//         for(int i=0;i<102;i++){
//             for(int j=0;j<102;j++){
//                 if(graph[i][j]==1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
        
       
//         if(canColour(0,adj,coloured,m,n)==true)return true;
//         return false;
//     }
// };
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isPlace(vector<int>adj[],vector<int>&color,int node,int col){
        for(auto it:adj[node]){
            if(color[it]==col)return false;
        }
        return true;
    }
    bool solve(vector<int>adj[],vector<int>&color,int node,int n,int m){
        if(node==n)return true;
        for(int i=1;i<=m;i++){
            if(isPlace(adj,color,node,i)==true){
                color[node]=i;
                if(solve(adj,color,node+1,n,m)==true)return true;
                else color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>adj[102];
        vector<int>color(102,0);
        for(int i=0;i<102;i++){
            for(int j=0;j<102;j++){
                if(graph[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        if(solve(adj,color,0,n,m)==true)return true;
        return false;
        
        
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