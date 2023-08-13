class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int n=str1.length();
        int m=str2.length();
        
        string one=str1+str2;
        string two=str2+str1;
        
        return one==two?one.substr(0,gcd(n,m)):"";
    }
};