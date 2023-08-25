//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
  int findOne(vector<int>&arr){
      int n=arr.size();
      int low=0,high=arr.size()-1;
      
      while(low<=high){
          int mid=(low+high)/2;
          if(arr[mid]==1){
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return n-low;
  }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int i=0;
	    int j=m-1;
	    int ind=-1;
	    int maxi=1e9;
	    while(i<n&&m>=0){
	        if(arr[i][j]==1){
	            j--;
	            if(j<maxi){
	            maxi=j;
	            ind=i;
	        }
	        }
	        else{
	            i++;
	        }
	        
	        
	        
	    }
	    return ind;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends