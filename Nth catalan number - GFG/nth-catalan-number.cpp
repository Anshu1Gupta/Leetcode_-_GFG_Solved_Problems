//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        int MOD=1e9+7;
        vector<int>catalan(n+1);
        catalan[0]=1,catalan[1]=1;
        for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] = (int)((catalan[i]+(long)catalan[j] * catalan[i-j-1]) % MOD);
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
       }
    }
    return catalan[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends