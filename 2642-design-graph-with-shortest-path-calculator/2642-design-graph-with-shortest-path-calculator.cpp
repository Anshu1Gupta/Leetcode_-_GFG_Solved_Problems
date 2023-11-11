// #pragma GCC optimize("O3")
class Graph {
    using int2=pair<int, int>;
    vector<vector<int2>> adj;
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) : n(n){
        adj.resize(n);
        #pragma unroll
        for(auto& edge: edges){
            adj[edge[0]].emplace_back(edge[2], edge[1]);
         }
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[2], edge[1]);
     }
    int shortestPath(int node1, int node2) {
        priority_queue<int2, vector<int2>, greater<int2>> pq;//minHeap
        vector<int> dist(n, INT_MAX);
        dist[node1]=0;
        pq.emplace(0, node1);// (distance, node)
        #pragma unroll
        while (!pq.empty()) {
            auto [d, i] = pq.top();
            pq.pop();
            if (i == node2) {
                addEdge({node1, node2, d});//Add this path as an edge
                return d;
            }
            if (d > dist[i]) continue;    
            int d2;
            #pragma unroll
            for (auto [w, j] : adj[i]) {
                d2=d+w;
                if (d2 < dist[j]) {
                    dist[j] = d2;
                    pq.emplace(d2, j);
                }
            }
        }
        return -1;
    }
};
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */