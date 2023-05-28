class Solution {
public:
    int myAtoi(string s) {
       double num=0;
        int i=0;
        while(i<s.length()&&s[i]==' '){
            i++;
        }
        bool positive=s[i]=='+';
        bool negative= s[i]=='-';
        positive==true?i++:i;
        negative==true?i++:i;
        
        while(i<s.length()&&(s[i]<='9'&&s[i]>='0')){
            num=num*10+(s[i]-'0');
            i++;
        }
        num=negative==true?-1*num:num;
        num=num>INT_MAX?INT_MAX:num;
        num=num<INT_MIN?INT_MIN:num;
        return num;
    }
};