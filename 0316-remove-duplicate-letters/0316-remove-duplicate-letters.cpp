class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastOccurence(26,0);
        vector<int>isPicked(26,0);
        
        string str;
        for(int i=0;i<s.size();i++){
            lastOccurence[s[i]-'a']=i;
        }
        for(int i=0;i<s.size();i++){
            int num=s[i]-'a';
            
            if(isPicked[num])continue;
            
            while(!str.empty()&&str.back()>s[i]&&lastOccurence[str.back()-'a']>i){
                isPicked[str.back()-'a']=0;
                str.pop_back();
            }
            str+=s[i];
            isPicked[num]=1;
        }
        return str;
      
    }
};