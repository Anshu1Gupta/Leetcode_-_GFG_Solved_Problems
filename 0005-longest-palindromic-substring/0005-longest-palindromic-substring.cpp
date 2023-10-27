class Solution {
public:
    string check(string &str,int low,int high){
        while(low>=0&&high<str.size()){
            if(str[low]==str[high]){
                low--,high++;
            }
            else break;
        }
        
        return str.substr(low+1,high-low-1);
        
    }
    string longestPalindrome(string s) {
        
        string ans;
        if(s.size()==1)return s;
        
        for(int i=0;i<s.size();i++){
            
            string str1=check(s,i,i);
            
            if(ans.size()<str1.size()){
                ans=str1;
            }
            
            string str2=check(s,i,i+1);
            if(ans.size()<str2.size()){
                ans=str2;
            }
        }
        return ans;
    }
};