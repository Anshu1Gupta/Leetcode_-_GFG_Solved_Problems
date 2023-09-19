//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minimum(int ind,int target,int coins[],vector<vector<int>>&dp){
	    if(ind==0){
	        if(target%coins[0]==0)return target/coins[0];
	        return 1e9;
	    }
	    if(dp[ind][target]!=-1)return dp[ind][target];
	    int take=1e9,ntake=1e9;
	    if(target>=coins[ind]){
	          take=1+minimum(ind,target-coins[ind],coins,dp);
	    }
	    ntake=0+minimum(ind-1,target,coins,dp);
	    return dp[ind][target]=min(take,ntake);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    sort(coins,coins+M);
	 int val= minimum(M-1,V,coins,dp);
	 if(val==1e9)return -1;
	 return val;
	    // Your code goes here
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends