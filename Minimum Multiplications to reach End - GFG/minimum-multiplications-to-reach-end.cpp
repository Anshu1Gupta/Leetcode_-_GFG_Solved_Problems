//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=1e5;
        vector<int>distance(100001,1e9);
        queue<pair<int,int>>q;
        q.push({start,0});
        distance[start]=0;
        
        if(start==end)return 0;
        while(!q.empty()){
            int node=q.front().first;
            int level=q.front().second;
            
            q.pop();
            
            for(auto it:arr){
                int num=(it*node)%mod;
                
                if(num==end)return level+1;
                
                if(distance[num]>level+1){
                    distance[num]=level+1;
                    q.push({num,level+1});
                }
            }
        }
        
        if(distance[end]==1e9)return -1;
        return distance[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends