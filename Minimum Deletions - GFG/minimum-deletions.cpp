//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minDelete(int ind1,int ind2, string &str1,string &str2,vector<vector<int>>&dp){
      if(ind1>=str1.size()||ind2>=str2.size())return 0;
      
      if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

      int take=0,ntake=0;
      if(str1[ind1]==str2[ind2]){
          return 1+minDelete(ind1+1,ind2+1,str1,str2,dp);
      }
      
      take=minDelete(ind1+1,ind2,str1,str2,dp);
      ntake=minDelete(ind1,ind2+1,str1,str2,dp);
      
      return dp[ind1][ind2]=max(take,ntake);
  }
    int minimumNumberOfDeletions(string S) { 
        string str1=S;
        string str2=S;
        int n=str2.size();
        reverse(str2.begin(),str2.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return S.size()-minDelete(0,0,str1,str2,dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends