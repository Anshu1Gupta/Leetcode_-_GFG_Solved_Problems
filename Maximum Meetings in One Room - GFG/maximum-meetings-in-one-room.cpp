//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
     vector<vector<int>>pair;
     int n=S.size();
     for(int i=0;i<S.size();i++){
         pair.push_back({S[i],F[i],i+1});
     }
     sort(pair.begin(),pair.end());
     
     vector<int>ans;
     int l=0;
     int r=1;
    //  for(auto it:pair){
    //      cout<<it[0]<<' '<<it[1]<<' '<<it[2]<<endl;
    //  }
     while(r<n){
         if(pair[l][1]<pair[r][0]){
             ans.push_back(pair[l][2]);
             l=r;
             r++;
         }
         else if(pair[l][1]<=pair[r][1]){
             r++;
         }
         else if(pair[l][1]>pair[r][1]){
             l=r;
             r++;
         }
     }
     if(ans.empty()||ans.back()!=pair[l][2])
        ans.push_back(pair[l][2]);
     sort(ans.begin(),ans.end());
     return ans;
     
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends