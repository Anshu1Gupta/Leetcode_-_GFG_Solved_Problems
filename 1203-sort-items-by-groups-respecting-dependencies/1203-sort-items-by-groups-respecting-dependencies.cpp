class Solution {
public:
        // Topological sort function
        vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& degrees) {
            vector<int> sorted;
            queue<int> q;
            // we start top sort from nodes with 0 degrees
            for (int i = 0; i < degrees.size(); ++i) {
                if (degrees[i] == 0) {
                    q.push(i);
                }
            }

            while (!q.empty()) {
                // remove u from graph
                int u = q.front();
                q.pop();
                sorted.push_back(u);
                // remove the edges from u -> v
                for (int v : graph[u]) {
                    // degree of v decreases
                    degrees[v]--;
                    // if is now 0 add it to queue
                    if (degrees[v] == 0) {
                        q.push(v);
                    }
                }
            }
            // if the whole graph could be sorted (no cycles) return its sorted order
            // if not return an empty vector signifying the top sort could not be ran
            return sorted.size() == graph.size() ? sorted : vector<int>();
        };
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Create a new group for items that don't belong to any group
        for (int u = 0; u < n; ++u) {
            if (group[u] == -1) {
                group[u] = m++;
            }
        }
        
        // Build directed graphs for items and groups
        // graph is for items
        // groupGraph is for groups
        vector<vector<int>> graph(n), groupGraph(m);

        // degrees keeps tack of items
        // group degrees keep track of a particular groups degrees
        vector<int> degrees(n, 0), groupDegree(m, 0);

        // creating the graphs
        for (int u = 0; u < n; ++u) {
            for (int v : beforeItems[u]) {
                graph[v].push_back(u); // v -> u
                degrees[u]++;
                // if they are not in the same group, add 1 degree to group[u]
                // also add the edge from group[v] -> group[u]
                if (group[u] != group[v]) {
                    groupGraph[group[v]].push_back(group[u]);
                    groupDegree[group[u]]++;
                }
            }
        }
        
        // Get topologically sorted items and groups
        vector<int> itemsSorted = topologicalSort(graph, degrees);
        vector<int> groupsSorted = topologicalSort(groupGraph, groupDegree);
        
        // if there is either a cycle in the items or in the groups graphs
        if (itemsSorted.empty() || groupsSorted.empty()) {
            return {};
        }
        
        // Order items based on group order
        vector<int> order;
        unordered_map<int, vector<int>> groupItems;

        // items are placed together based on their group
        for (int v : itemsSorted) {
            groupItems[group[v]].push_back(v);
        }

        // in sorted order of the groups, place each item of the group into the final output
        for (int group : groupsSorted) {
            for (int item : groupItems[group]) {
                order.push_back(item);
            }
        }

        return order;
    }
};