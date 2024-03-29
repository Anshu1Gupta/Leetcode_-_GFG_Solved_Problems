//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    queue<int>pos;
	    queue<int>neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            neg.push(arr[i]);
	        }
	        else{
	            pos.push(arr[i]);
	        }
	    }
	    for(int i=0;i<n;i++){
	         if(pos.empty()){
	            while(!neg.empty()){
	                
	                arr[i]=neg.front();
	                neg.pop();
	                i++;
	            }
	            break;
	        }
	        else if(neg.empty()){
	            while(!pos.empty()){
	               
	                arr[i]=pos.front();
	                pos.pop();
	                 i++;
	            }
	            break;
	        }
	        if(i%2==0){
	            arr[i]=pos.front();
	            pos.pop();
	        }
	        else{
	            arr[i]=neg.front();
	            neg.pop();
	        }
	       
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends