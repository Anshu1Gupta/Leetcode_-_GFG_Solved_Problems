//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    int findSt(int arr[],int mid,int n){
        int stu=1;
        int pa=0;
        
        for(int i=0;i<n;i++){
            if(pa+arr[i]<=mid){
                pa+=arr[i];
            }
            else{
                stu++;
                pa=arr[i];
            }
        }
        return stu;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if( M>N)return -1;
        
        int low=*max_element(A,A+N);
        int high=0;
        for(int i=0;i<N;i++){
            high+=A[i];
        }
        
        
        while(low<=high){
            int mid=(low+high)/2;
            
            int stud=findSt(A,mid,N);
            if(stud>M){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends