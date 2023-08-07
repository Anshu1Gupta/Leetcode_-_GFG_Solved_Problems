//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        int count=0;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            int gcd=__gcd(numerator[i],denominator[i]);
        numerator[i]=numerator[i]/gcd;
        denominator[i]=denominator[i]/gcd;
     
        int num=denominator[i]-numerator[i];
        
        
        string find=to_string(num)+"and"+to_string(denominator[i]);
               
        string str=to_string(numerator[i])+"and"+to_string(denominator[i]);
        count+=mp[find];
        mp[str]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends