class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')return true;
            return false;
    }
    int maxVowels(string s, int k) {
        
        int start=0;
        // int end=0;
        
        int n=s.length();
        int ans=0;
        int count=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i]))count++;
        }
        int end=k;
        
        ans=max(ans,count);
        while(end<n){
            
            if(isVowel(s[start]))count--;
            start++;
            if(isVowel(s[end]))count++;
            end++;
            
            ans=max(ans,count);
            
            
        }
        return ans;
    }
};