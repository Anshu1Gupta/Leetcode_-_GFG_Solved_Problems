class Solution {
public:
   static bool cmp(string a, string b){
         return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>ans;
        for(auto it:nums){
            string str=to_string(it);
            ans.push_back(str);
        }
        sort(ans.begin(),ans.end(),cmp);
        string str;
        for(auto it:ans){
            str+=it;
        }
        int n=str.size();
        for(int i=0;i<str.size()-1;i++){
            if(str[i]!='0'){
                return str.substr(i,n);
            }
        }
        return str.substr(n-1,n);
    }
};