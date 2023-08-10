//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
long long int ans(int *coins,int ind,int target, vector<vector<long long int>>&dp){
   if(ind==0)
   {
      return (target%coins[0]==0);
   }
      if(dp[ind][target]!=-1)return dp[ind][target];
      
      
      long long int ntake=ans(coins,ind-1,target,dp);
      
      
      long long int take=0;
      if(coins[ind]<=target){
          take=ans(coins,ind,target-coins[ind],dp);
      }
      
      return dp[ind][target]=take+ntake;
  }

    long long int count(int coins[], int N, int sum) {
      vector<vector<long long int>>dp(N,vector<long long int>(sum+1,0));
      
      for(int i=0;i<=sum;i++){
         if(i%coins[0]==0)
          dp[0][i]=1;
      }
      
      for(int ind=1;ind<N;ind++){
          for(int target=0;target<=sum;target++){
              long long int take=0;
              long long int ntake=dp[ind-1][target];
              if(target>=coins[ind]){
                  take=dp[ind][target-coins[ind]];
              }
              
              dp[ind][target]=take+ntake;
          }
      }
      
      return dp[N-1][sum];
    //   return ans(coins,N-1,sum,dp);
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends