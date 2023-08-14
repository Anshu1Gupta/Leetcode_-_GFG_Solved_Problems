class Solution {
public:
    
    string decodeString(string s) {
        
        string res;
        int num=0;
        stack<int>nums;
        stack<string>chars;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(c=='['){
                chars.push(res);
                nums.push(num);
                num=0;
                res="";
            }
            else if(c==']'){
                string temp=res;
                res=chars.top();
                chars.pop();
                for(int i=nums.top();i>0;i--)res+=temp;
                nums.pop();
            }
            else{
                res+=c;
            }
        }
        return res;
        
        
        
    }
};