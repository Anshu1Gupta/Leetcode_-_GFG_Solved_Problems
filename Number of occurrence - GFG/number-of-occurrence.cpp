//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
	    
	    int low=0;
	    int high=n-1;
	    
	    while(low<=high){
	        int mid=(low+high)/2;
	        
	        if(arr[mid]>=x)high=mid-1;
	        else low=mid+1;
	    }
	    
	    int low2=0;
	    int high2=n-1;
	    while(low2<=high2){
	        int mid2=(low2+high2)/2;
	        if(arr[mid2]<=x)low2=mid2+1;
	        else high2=mid2-1;
	    }
	    
	    return low2-low;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends