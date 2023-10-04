//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    
int convert(char ch){
    if(ch=='I')return 1;
    if(ch=='V')return 5;
    if(ch=='X')return 10;
    if(ch=='L')return 50;
    if(ch=='C')return 100;
    if(ch=='D')return 500;
    if(ch=='M')return 1000;
return 1;
}
    int romanToDecimal(string &s) {
        int sum=0;
        int n=s.length();
      for(int i=0;i<s.length();i++){
          if(i+1<n&&convert(s[i])<convert(s[i+1])){
              int x=convert(s[i]);
              int y=convert(s[i+1]);
              sum=sum+y-x;
              i++;
          }
          else
          sum=sum+convert(s[i]);
         
        //   cout<<sum<<endl;
      }
      return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends