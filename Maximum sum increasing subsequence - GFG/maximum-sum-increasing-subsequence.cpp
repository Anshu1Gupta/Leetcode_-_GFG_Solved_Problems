//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes 
	    int maxi=-1;
	    vector<int>dp(n+1,0);
	    
	   unordered_map<int,int>mp;
	   for(int i=0;i<n;i++){
	       dp[i]=arr[i];
	       for(int j=0;j<i;j++){
	           if(arr[i]>arr[j]&&arr[i]+dp[j]>dp[i]){
	               dp[i]=arr[i]+dp[j];
	           }
	       }
	       
	       maxi=max(maxi,dp[i]);
	   
	       //cout<<maxi<<endl;
	   }
	   return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends