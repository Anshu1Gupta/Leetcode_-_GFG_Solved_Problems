class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return true;
        return false;
    }
    bool halvesAreAlike(string s) {
       int n=s.length();
       int h=n/2;
        int count=0;
        for(int i=0;i<h;i++){
            if(isVowel(s[i]))count++;
        }
        for(int i=h;i<n;i++){
            if(isVowel(s[i]))count--;
        }
        
        return count==0?true:false;
    }
};