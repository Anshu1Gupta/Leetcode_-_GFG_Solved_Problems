class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i=0;
        int j=0;
        int m=s.length();
        int n=t.length();
        while(j<n&&i<m){
            if(s[i]==t[j]){
                i++;
            }
            if(i==m)break;
            j++;
        }
        
        if(i==m)return true;
        else return false;
    }
};