//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	int dfs(int node , int lev , vector<int> &vis , vector<int> adj[] , int X){
	    if(node == X) return lev;
	    vis[node] = 1;
	    
	    for(auto it : adj[node]){
	        if(!vis[it]) {
	            int level = dfs(it , lev+1 , vis , adj , X);
	            if(level != -1) return level;
	        }
	    }
	    
	    return -1;
	}
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<int> vis(V , 0);
	    return dfs(0 , 0 , vis , adj , X);
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends