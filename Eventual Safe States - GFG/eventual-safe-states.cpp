//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool dfs(int u,int V,vector<int>adj[],vector<int>&path,int visited[],int check[]){
        
      visited[u]=1;
      path[u]=1;
      check[u]={0};
      for(auto v:adj[u]){
         if(!visited[v]){
             if(dfs(v,V,adj,path,visited,check)){
              return true;
          }
         }
         else if(path[v]!=-1){
             return true;
         }
      }
      check[u]=1;
      path[u]=-1;
   return false;
     
    }
  public:
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
         int visited[V]={0};
         vector<int>path(V,-1);
         int check[V]={0};
       for(int i=0;i<V;i++){
            
           if(!visited[i]){
               dfs(i,V,adj,path,visited,check);
           }
       }
       for(int i=0;i<V;i++){
           if(check[i]==1){
               ans.push_back(i);
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends