//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int n=s1.size()-1,m=s2.size()-1;
       int s1s=0,s2s=0;
       int sign=1;
       if(s1[0]=='-')s1s++,sign*=-1;
       if(s2[0]=='-')s2s++,sign*=-1;
       vector<int>res(n+m+2,0);
       for(int j=m;j>=s2s;j--){
           int c=0 , idx=s2.size()-j-1;
           for(int i=n;i>=s1s;i--,idx++){
               int sum=(s1[i]-'0')*(s2[j]-'0')+c;
               res[idx]+=sum%10;
               c=sum/10;
           }
           res[idx]+=c;
       }
        int c=0;
        for(int &i:res){
            int temp=(i+c)%10;
            c=(i+c)/10;
            i=temp;
        }
        int i=res.size()-1;
        string ans;
        while(res[i]==0)i--;
        while(i>=0)ans.push_back(res[i--]+'0');
       if(ans.size()==0)return "0";
       return sign==-1?"-"+ans:ans;
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends