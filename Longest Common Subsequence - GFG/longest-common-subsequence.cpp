//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    
    int longest(int ind1,int ind2,string &str1,string &str2,vector<vector<int>>&dp){
        if(ind1<0||ind2<0)return 0;
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(str1[ind1]==str2[ind2]){
            return dp[ind1][ind2]=1+longest(ind1-1,ind2-1,str1,str2,dp);
        }
        
        int take1=longest(ind1-1,ind2,str1,str2,dp);
        int take2=longest(ind1,ind2-1,str1,str2,dp);
        
        
        return dp[ind1][ind2]=max(take1,take2);
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // int n=s1.length();
        // int m=s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return longest(n-1,m-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends