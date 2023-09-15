//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int n=txt.size();
            int m=pat.size();
            int x_m=1;
            int x=19;
            int mod=301;
            
            int hash_p=0;
            int hash_t=0;
            for(int i=1;i<=m-1;i++){
                x_m=(x_m*x)%mod;
            }
            vector<int>ans;
            for(int i=0;i<m;i++){
                hash_p=(hash_p*x+pat[i])%mod;
                hash_t=(hash_t*x+txt[i])%mod;
            }
            
            for(int i=0;i<(n-m+1);i++){

                
                if(hash_p==hash_t){
                    bool found=true;
                    for(int j=0;j<m;j++){
                        if(pat[j]!=txt[i+j]){
                            found=false;
                            break;
                        }
                    }
                    if(found)ans.push_back(i+1);
                }
                
                if(i<(n-m)){
                    hash_t=(x*(hash_t-x_m*txt[i])+txt[i+m])%mod;
                    if(hash_t<0)hash_t+=mod;
                }
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