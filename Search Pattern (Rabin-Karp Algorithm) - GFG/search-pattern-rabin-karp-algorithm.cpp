//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int n=txt.size();
            int m=pat.size();
            
            int x=13;
            int x_m=1;
            
            int hashP=0;
            int hashT=0;
            int mod=301;
            for(int i=0;i<m-1;i++){
                x_m=(x*x_m)%mod;
            }
            
            for(int i=0;i<m;i++){
                hashP=(hashP*x+pat[i])%mod;
                hashT=(hashT*x+txt[i])%mod;
            }
            
            vector<int>ans;
            for(int i=0;i<(n-m)+1;i++){
                if(hashP==hashT){
                    int j=0;
                    for(;j<m;j++){
                        if(pat[j]!=txt[i+j]){
                            break;
                        }
                        
                    }
                    if(j==m){
                        ans.push_back(i+1);
                    }
                }
                if(i<(n-m))
                hashT=(x*(hashT-txt[i]*x_m)+txt[i+m])%mod;
                
                if(hashT<0)hashT+=mod;
            }
            if(ans.size()==0)return {-1};
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends