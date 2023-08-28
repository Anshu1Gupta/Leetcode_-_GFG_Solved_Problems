//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
       long long int pro=1;
       int count=0;
       for(int i=0;i<n;i++){
           if(nums[i]==0)count++;
           
           else{
               pro=pro*nums[i];
           }
       }
       
       vector<long long int>ans(n);
       for(int i=0;i<n;i++){
           if(count>1){
               ans[i]=0;
           }
           else if(count==1){
               if(nums[i]==0){
                   ans[i]=pro;
               }
               else{
                   ans[i]=0;
               }
           }
           else{
               ans[i]=pro/nums[i];
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends