//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    
public:
vector<int>parent,size;
  DisjointSet(int n){
     parent.resize(n);
     size.resize(n);
     for(int i=0;i<n;i++){
       parent[i]=i;
       size[i]=1;
     }
   }
 
   int findUPar(int node){
     if(node==parent[node]){
       return parent[node];
     }
     return parent[node]=findUPar(parent[node]);
   }
   void unionBySize(int u,int v){
      int ult_pu=findUPar(u);
      int ult_pv=findUPar(v);
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
class Solution {
  public:
	int Solve(int n, vector<vector<int>>& edges) {
    	     int extraEdges=0;
           DisjointSet ds(n);
           for(auto it:edges){
               int u=it[0],v=it[1];
               if(ds.findUPar(u)!=ds.findUPar(v)){
                    ds.unionBySize(u,v);
               }
               else{
                     extraEdges++;
                   }
           }
         int count=0;
         for(int i=0;i<n;i++){
           if(ds.parent[i]==i)count++;
         }

       if(count-1<=extraEdges)return count-1;
       return -1;
        
	
}
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends