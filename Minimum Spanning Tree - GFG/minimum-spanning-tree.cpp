//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int>parent,size;
public:
    DisjointSet(int n){
      parent.resize(n+1),size.resize(n+1);
      for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
      }
    }


    int findParent(int node){
       if(node==parent[node]){
          return parent[node];
       }
       return parent[node]=findParent(parent[node]);
    }
    
    void unionBySize(int u,int v){
      int ult_pu=findParent(u);
      int ult_pv=findParent(v);
      
      if(ult_pu==ult_pv)return;
      if(size[ult_pu]>size[ult_pv]){
        size[ult_pu]+=size[ult_pv];
        parent[ult_pv]=ult_pu;
      }
      else{
         size[ult_pv]+=size[ult_pu];
         parent[ult_pu]=ult_pv;
      }
    }
};
class Solution
{
    public:
  int spanningTree(int V, vector<vector<int>> adj[])
{
    DisjointSet ds(V);
    vector<pair<int,pair<int,int>>>pairs;
    for(int i=0;i<V;i++){
      for(auto it:adj[i]){
        int u=i;
        int v=it[0];
        int cost=it[1];
        pairs.push_back({cost,{u,v}});
      }
    }
     int finalWeight=0;
     sort(pairs.begin(),pairs.end());
     for(auto it:pairs){
        int cost=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findParent(u)!=ds.findParent(v)){
           finalWeight+=cost;
           ds.unionBySize(u,v);
        }
     }
      return finalWeight;	
}
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends