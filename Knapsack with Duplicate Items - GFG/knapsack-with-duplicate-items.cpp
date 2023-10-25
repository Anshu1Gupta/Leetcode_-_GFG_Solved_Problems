//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int maximum(int ind,int weight,int val[],int wt[],vector<vector<int>>&dp,int size){
      if(ind>=size)return 0;
      
      if(dp[ind][weight]!=-1)return dp[ind][weight];
      
      int take=0,ntake=0;
      
      if(weight>=wt[ind]){
          take=val[ind]+maximum(ind,weight-wt[ind],val,wt,dp,size);
      }
      ntake=maximum(ind+1,weight,val,wt,dp,size);
      
      dp[ind][weight]=max(take,ntake);
  }
    int knapSack(int N, int W, int val[], int wt[])
    {
       int n=N;
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return maximum(0,W,val,wt,dp,n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends