//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
    
        int first=-1;
        int second=-1;
        
        int low=0,high=n-1;
        int flag=0;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]==x){
                flag=1;
            }
            if(arr[mid]>=x){
                first=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        low=0;high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]<=x){
                second=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        if(flag==0)return {-1,-1};
        
        return {first,second};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends