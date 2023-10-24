//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPallindrome(string &str){
    int low=0;
    int high=str.size()-1;
    
    while(low<=high){
        if(str[low]!=str[high])return false;
        low++;high--;
    }
    return true;
}
    int partition(int ind, string &str, vector<int>&dp){
        
        if(ind>=str.size())return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        int count=INT_MAX;
        for(int i=ind;i<str.size();i++){
            string st=str.substr(ind,i-ind+1);
            
            if(isPallindrome(st)){
                count=min(count,1+partition(i+1,str,dp));
            }
        }
        dp[ind]=count;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n,-1);
        return partition(0,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends