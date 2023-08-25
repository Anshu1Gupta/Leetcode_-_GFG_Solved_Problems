//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int low=0;
    int high=n-1;
    if(arr[low]==arr[high]&&arr[0]==0)return -1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==1){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
       
    }
     return low;
}