//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod=1e9+7;
    int nthFibonacci(int n){
        // code here
        
        if(n==1)return 0;
        if(n==2)return 1;
        int prev=1;
        int sum=1;
        for(int i=3;i<=n;i++){
            int val=(sum%mod+prev%mod)%mod;
            prev=sum%mod;
            sum=val%mod;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends