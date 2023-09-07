//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
      sort(arr,arr+n);
      int count=0;
      
      for(int i=0;i<n;i++){
          if(i>0){
              if(arr[i]==arr[i-1])continue;
          }
          int low=i+1;
          int high=n-1;
          
          while(low<high){
             int sum=arr[i]+arr[low]+arr[high];
             
             if(sum>0)high--;
             else if(sum<0)low++;
             else{
                 count++;
                 
                 int ind1=low;
                 int ind2=high;
                 
                 while(arr[low]==arr[ind1])low++;
                 while(arr[high]==arr[ind2])high--;
             }
          }
      }
      return count;
      
    //   return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends