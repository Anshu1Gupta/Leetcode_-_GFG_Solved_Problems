//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
         int first=0;
        int last=m-1;
         int l1=-1;
         int r2=-1;
        int diff=INT_MAX;
        while(first<n&&last>=0){
            int sum=arr[first]+brr[last];
            
            if(diff>abs(sum-x)){
                diff=abs(sum-x);
                l1=arr[first];
                r2=brr[last];
            }
            if(sum<x)first++;
            else if(sum>x)last--;
            else {
                return {arr[first],brr[last]};
            }
        }
   
        return {l1,r2};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends