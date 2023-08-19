// class Solution {
// public:
//     int N;
//     class UnionFind {
//         public:
//             vector<int> parent;
//             vector<int> rank;

//             UnionFind(int n) {
//                 parent.resize(n);
//                 rank.resize(n, 0);
//                 for (int i = 0; i < n; i++) {
//                     parent[i] = i;
//                 }
//             }    
        
//             int find (int x) {
//                 if (x == parent[x]) 
//                     return x;

//                 return parent[x] = find(parent[x]);
//             }

//             void Union (int x, int y) {
//                 int x_parent = find(x);
//                 int y_parent = find(y);

//                 if (x_parent == y_parent) 
//                     return;

//                 if(rank[x_parent] > rank[y_parent]) {
//                     parent[y_parent] = x_parent;
//                 } else if(rank[x_parent] < rank[y_parent]) {
//                     parent[x_parent] = y_parent;
//                 } else {
//                     parent[x_parent] = y_parent;
//                     rank[y_parent]++;
//                 }
//             }
//     };
    
//     int Kruskal(vector<vector<int>> &vec, int skip_edge, int force_edge) {

//         int sum = 0;
//         UnionFind uf(N);
        
//         if(force_edge != -1) {
//             uf.Union(vec[force_edge][0], vec[force_edge][1]);
//             sum += vec[force_edge][2];
//         }
        
//         for(int i=0; i < vec.size(); i++) {
            
//             if(i == skip_edge)
//                 continue;
            
//             int u  = vec[i][0];
//             int v  = vec[i][1];
//             int wt = vec[i][2];
            
//             int parent_u = uf.find(u);
//             int parent_v = uf.find(v);
            
//             if(parent_u != parent_v) {
//                 uf.Union(u, v);
//                 sum += wt;
//             }
            
//         }

//         //Check if all vertices are included in MST
//         for(int i = 0; i < N; i++) {
//             if(uf.find(i) != uf.find(0))
//                 return INT_MAX;
//         }
        
//         return sum;
//     }
    
//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//         N = n;
        
//         //since for kruskal's algo, we will sort our input by edge weight.
//         //But since we need to return the index in the last
//         for(int i = 0; i < edges.size(); i++) {
//             edges[i].push_back(i);
//         }
        
//         auto comparator = [&](auto &v1, auto &v2) {
//             return v1[2] < v2[2];
//         };
//         //Now sort based on weight
//         //O(ElogE)
//         sort(edges.begin(), edges.end(), comparator);
        
        
//         //Find MST now
//         //Find MST weight using union-find
//         //O(E*@)
//         int MST_WEIGHT = Kruskal(edges, -1, -1);
        
//         vector<int> critical, pseudo_critical;


//       //O(E*E*@)
//         for(int i = 0; i < edges.size(); i++) {
          
//             if(Kruskal(edges, i, -1) > MST_WEIGHT) //Skipping ith edge
//                 critical.push_back(edges[i][3]); 
            
//             else if(Kruskal(edges, -1, i) == MST_WEIGHT) // Force add ith edge
//                 pseudo_critical.push_back(edges[i][3]);
//         }

//         return {critical, pseudo_critical};
        
//     }
// };


// //Approach-2 (Better Kruskal's Function)
// /*
// If you remember, in the Kruskal's Function, in the end we checked if the graph was connected and wrote a for loop to check that as shown below : 
// for(int i = 0; i<N; i++) {   
//             if(uf.find(i) != uf.find(0))
//                 return INT_MAX;
//  }

// BUT BUT BUT, we can also directly check if the total edges we made from Union is equal to (V-1). 
// Remember, in MST, there must be V vertices and must have (V-1) edges.
// So, in Kruskal's function, whenever you do Union, just count the edges you draw.

// So, simply replace the for loop with : 
// if(edgesConnected != N-1)
//             return INT_MAX;

// Full code below :
// */
class Solution {
public:
    int N;
    class UnionFind {
        public:
            vector<int> parent;
            vector<int> rank;

            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }    
        
            int find (int x) {
                if (x == parent[x]) 
                    return x;

                return parent[x] = find(parent[x]);
            }

            bool Union (int x, int y) {
                int x_parent = find(x);
                int y_parent = find(y);

                if (x_parent == y_parent) 
                    return false;

                if(rank[x_parent] > rank[y_parent]) {
                    parent[y_parent] = x_parent;
                } else if(rank[x_parent] < rank[y_parent]) {
                    parent[x_parent] = y_parent;
                } else {
                    parent[x_parent] = y_parent;
                    rank[y_parent]++;
                }
                return true;
            }
    };
    
    int Kruskal(vector<vector<int>> &vec, int skip_edge, int add_edge) {

        int sum = 0;
        
        UnionFind uf(N);
        int edgesConnected = 0;
        
        if(add_edge != -1) {
            uf.Union(vec[add_edge][0], vec[add_edge][1]);
            sum += vec[add_edge][2];
            edgesConnected++;
        }
        
        //E
        
        for(int i = 0; i<vec.size(); i++) {
            
            if(i == skip_edge)
                continue;
            
            int u  = vec[i][0];
            int v  = vec[i][1];
            int wt = vec[i][2];
            //O(@)
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            
            if(parent_u != parent_v) {
                uf.Union(u, v);
                edgesConnected++;
                sum += wt;
            }
            
        }

        if(edgesConnected != N-1)
            return INT_MAX;
        
        return sum;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i = 0; i<edges.size(); i++) {
            edges[i].push_back(i);  
        }
        
        auto lambda = [&](vector<int>& vec1, vector<int>& vec2) {
            return vec1[2] < vec2[2];
        };
        //ElogE
        sort(begin(edges), end(edges), lambda);
        
        
        int MST_WEIGHT = Kruskal(edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo_critical;
        
        
        //E*E*@
        for(int i = 0; i<edges.size(); i++) {
            
            if(Kruskal(edges, i, -1) > MST_WEIGHT) { //skipping ith edge
                critical.push_back(edges[i][3]);
            }
            
            else if(Kruskal(edges, -1, i) == MST_WEIGHT) { //Force add this ith edge
                pseudo_critical.push_back(edges[i][3]);
            }
            
        }
        
        
        return {critical, pseudo_critical};
        
    }
};
// class DisjointSet {
//     vector<int> rank, parent, size;
// public:
//     DisjointSet(int n) {
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionByRank(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//         }
//         else if (rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u;
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };


// class Solution {
//     int findMST(vector<vector<int>>&adj){
    
//         DisjointSet ds(V);
       
//         int mstWt = 0;
//         for (auto it : adj) {
//             int wt = it[0]
//             int u = it[1]
//             int v = it[2]

//             if (ds.findUPar(u) != ds.findUPar(v)) {
//                 mstWt += wt;
//                 ds.unionBySize(u, v);
//             }
//         }

//         return mstWt;
// }
//     bool changeInMST(vector<int>&adj,int i,int key){
//         DisjointSet ds(V);
       
//         int mstWt = 0;
//         for(int k=0;k<adj.size()&&k!=i;k++) {
//             int wt = adj[k][0]
//             int u = adj[k][1]
//             int v = adj[k][2]

//             if (ds.findUPar(u) != ds.findUPar(v)) {
//                 mstWt += wt;
//                 ds.unionBySize(u, v);
//             }
//         }

//         return mstWt>key;
        
//     }
// public:
//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//         int n=edges.size();
//         vector<vector<int>>adj;
//         for(int i=0;i<edges.size();i++){
//             int u=edges[i][0];
//             int v=edges[i][1];
//             int wt=edges[i][2];
//             adj.push_back({wt,u,v,i});
//         }
        
//         sort(adj.begin(),adj.end());
        
//         int mst_val=findMST(adj);
//         vector<int>first,second;
//         for(int i=0;i<adj.size();i++){
//             if(!changeInMST(adj,i,mst_val)){
//                 first.push_back(adj[i][3]);
//             }
//             else if(sameMST(adj,i,mst_val)){
//                 second.push_back(adj[i][3]);
//             }
//         }
//         vector<vector<int>>ans;
//          ans.push_back(first);
//         ans.push_back(second);
//         return ans;
//     }
// };