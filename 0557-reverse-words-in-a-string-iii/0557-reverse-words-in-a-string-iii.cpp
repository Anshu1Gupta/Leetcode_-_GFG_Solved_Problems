class Solution {
public:
bool space(char c){
    if(c==' ')return true;
    else return false;
}

    string reverseWords(string s) {
        int start=0;
        int i=0;
        for(;i<s.length();i++){
            if(s[i]==' '){
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
            }
        }
        reverse(s.begin()+start,s.begin()+i);
         return s;
    }
   
};