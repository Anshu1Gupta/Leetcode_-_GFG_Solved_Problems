class Solution {
public:
    bool isVowel(char str){
    if(str=='a'||str=='e'||str=='i'||str=='o'||str=='u'||str=='A'||str=='E'||str=='I'||str=='O'||str=='U')return true;
        return false;
    }
    string reverseVowels(string s) {
        int n=s.length();
        int low=0;
        int high=n-1;
        
        while(low<=high){
            while(low<=high&&!isVowel(s[low]))low++;
            while(high>=low&&!isVowel(s[high]))high--;
            
            if(low<=high)swap(s[low],s[high]);
            low++;high--;
        }
        return s;
    }
};