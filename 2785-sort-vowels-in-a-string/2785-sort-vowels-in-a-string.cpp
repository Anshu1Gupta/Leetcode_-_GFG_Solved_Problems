class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')return true;
        return false;
    }
    string sortVowels(string s) {
        
       vector<char>qarr;
        
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                qarr.push_back(s[i]);
            }
        }
        queue<char>q;
        sort(qarr.begin(),qarr.end());
        for(int i=0;i<qarr.size();i++){
            q.push(qarr[i]);
        }
        
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=q.front();
                q.pop();
            }
        }
        return s;
        
    }
};