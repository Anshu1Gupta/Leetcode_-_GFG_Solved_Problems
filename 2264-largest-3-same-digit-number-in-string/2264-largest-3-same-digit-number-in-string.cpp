class Solution {
public:
    string largestGoodInteger(string num) {
        
        string ans="";
        
        for(int i=1;i<num.size()-1;i++){
            if(num[i]==num[i-1]&&num[i]==num[i+1]){
                string str;
                str+=num[i-1];
                str+=num[i];
                str+=num[i+1];
                // cout<<str<<endl;
                ans=max(ans,str);
            }
        }
        return ans;
    }
};