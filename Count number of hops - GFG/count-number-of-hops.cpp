//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        int mod=1e9+7;
         long long a=1,b=2,c=4;
   
      for(long long i=4;i<=n;i++){
          long long temp=(a+b+c)%mod;
          a=b;
          b=c;
          c=temp;
      }
      
      if(n==1)return a;
      if(n==2)return b;
      if(n==3)return c;
      return c;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends