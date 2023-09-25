//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
         sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        priority_queue<vector<int>>pq;
        for(int i=N-1;i>=0;i--){
            pq.push({A[i]+B[N-1],i,N-1});
        }
        
        vector<int>ans;
        
        while(K--&&!pq.empty()){
            int val=pq.top()[0], i=pq.top()[1],j=pq.top()[2];pq.pop();
            ans.push_back(val);
            pq.push({A[i]+B[j-1],i,j-1});
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends