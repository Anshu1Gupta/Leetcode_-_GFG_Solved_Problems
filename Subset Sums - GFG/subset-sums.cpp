//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

void finSets(int ind,vector<int>&arr,vector<int>&temp,int sum){
    if(ind>=arr.size()){
        temp.push_back(sum);
        return;
    }
    finSets(ind+1,arr,temp,sum+arr[ind]);
    finSets(ind+1,arr,temp,sum);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>temp;
        int sum=0;
        
        finSets(0,arr,temp,sum);
        return temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends