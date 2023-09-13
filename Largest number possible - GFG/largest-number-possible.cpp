//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
       if(S==0&&N==1)return "0";
       if(S==0&&N>1)return "-1";
       
       if(S<=9){
           string str;
           str+=S+('0');
           while(str.size()<N)str+='0';
           return str;
       }
       
       if(ceil(S/(9.0))>N)return "-1";
       int num=S/9;
       int p=S%9;
       
       string str;
       while(num--){
           str+='9';
       }
       if(p!=0)
       str+=p+'0';
       
       while(str.size()<N)str+='0';
       
    //   while(str.size()>N)str.pop_back();
       return str;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends