//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        if(a.size()!=b.size())return false;
        map<int,int>mp1,mp2;
        
        for(int i=0;i<a.length();i++){
            mp1[a[i]]++;
            mp2[b[i]]++;
        }
        
        for(int i=0;i<26;i++){
            char x='a'+i;
            if(mp1[x]!=mp2[x])return false;
        }
        return true;
        
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends