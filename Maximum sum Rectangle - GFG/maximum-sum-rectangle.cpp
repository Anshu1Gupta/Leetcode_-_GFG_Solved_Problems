//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

int findSubMat(vector<int>&arr){
   int maxi=INT_MIN;
   
   int sum=0;
   for(int i=0;i<arr.size();i++){
       sum+=arr[i];
       maxi=max(maxi,sum);
       
       if(sum<0)sum=0;
   }
   return maxi;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> A) {
        
   int n=A.size();
   int m=A[0].size();
   int count=INT_MIN;
   vector<int>rect(m);
   for(int i=0;i<A.size();i++)                    //Convert 2D array to 1D by row.
        {
            fill(rect.begin(),rect.end(),0);                  //Clear vector to start the rect with i as starting rect.
            for(int j=i;j<A.size();j++)
            {
                for(int x=0;x<A[0].size();x++)         
                    rect[x]+=A[j][x];
                count=max(count,findSubMat(rect));
            }
        }
    
   return count;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends