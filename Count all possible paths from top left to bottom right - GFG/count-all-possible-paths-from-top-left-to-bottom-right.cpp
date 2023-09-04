//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod=1e9+7;
    long long poss(int i,int j,vector<vector<long long>>&dp){
        if(i==0&&j==0)return 1;
        if(i<0||j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        long long left=poss(i,j-1,dp)%mod;
        long long up=poss(i-1,j,dp)%mod;
        
        return dp[i][j]=(left%mod+up%mod)%mod;
    }
    long long int numberOfPaths(int n, int m){
       
       vector<vector<long long>>dp(n,vector<long long>(m,-1));
       return poss(n-1,m-1,dp);
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends