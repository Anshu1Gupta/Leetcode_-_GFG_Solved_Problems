//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
  
        vector<int>arr;
        int perm=1;
        string str="";
        for(int i=1;i<n;i++){
            arr.push_back(i);
            perm=perm*i;
        }
        arr.push_back(n);
        k--;
        
        while(true){ 
        str+=to_string(arr[k/perm]);
        arr.erase(arr.begin()+k/perm);
        if(arr.size()==0)break;
        k=k%perm;
        perm=perm/(arr.size());
            
         }
        
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends