//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
           string str;
           int count=0;
           for(int i=0;i<s.length();i++)
           {
               if(s[i]=='.')
               {
                   count++;
                   if(str.size()>=4||(str.size()>=2&&str[0]=='0'))return 0;
                   if(str.empty())return 0;
                   
                   int num=stoi(str);
                   if(num>255)return 0;
                   str="";
                   
               }
               else
               {
                   if(!(s[i]>='0'&&s[i]<='9'))return 0;
                  str+=s[i];
               }
           }
           if(str.size()>=4||(str.size()>=2&&str[0]=='0'))return 0;
                   if(str.empty())return 0;
                   int num=stoi(str);
                   if(num>255)return 0;
               
               if(count!=3)return 0;
                   return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends