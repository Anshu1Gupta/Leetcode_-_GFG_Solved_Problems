//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int theCut(int target,int x,int y,int z,vector<int>&dp){
        if(target<0)return -1e9;
        if(target==0)return 0;
        
        if(dp[target]!=-1)return dp[target];
        int first=1+theCut(target-x,x,y,z,dp);
        int second=1+theCut(target-y,x,y,z,dp);
        int third=1+theCut(target-z,x,y,z,dp);
        
        return dp[target]=max(max(first,second),third);
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
       return max(theCut(n,x,y,z,dp),0);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends