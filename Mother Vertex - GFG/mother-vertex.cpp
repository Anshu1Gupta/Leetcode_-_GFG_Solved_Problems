//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
     void dfs(int source, vector<int>&visited,vector<int>adj[]){
        visited[source]=1;
        for(auto it:adj[source]){
            if(!visited[it])dfs(it,visited,adj);
        }
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int ans=0;
	    vector<int>visited(V,0);
	   
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,visited,adj);
	            ans=i;
	        }
	    }
	    
	   fill(visited.begin(),visited.end(),0);
	    dfs(ans,visited,adj);
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i])return -1;
	    }
	    return ans;
	   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends