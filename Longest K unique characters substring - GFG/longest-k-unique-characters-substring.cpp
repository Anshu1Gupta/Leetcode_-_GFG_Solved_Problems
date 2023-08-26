//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
     unordered_map<char,int>mp;
    int maxi=-1;
    int n=s.length();
    int end=0;
    int start=0;
    
    while(end<n){
        mp[s[end]]++;
        
        if(mp.size()==k){
            int len=end-start+1;
            maxi=max(len,maxi);
        }
        else{
            while(mp.size()>k){
                mp[s[start]]--;
                if(mp[s[start]]==0){
                    mp.erase(s[start]);
                }
                start++;
            }
        }
        end++;
    }
    return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends