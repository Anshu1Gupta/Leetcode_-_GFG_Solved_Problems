class Solution {
public:
    bool isPallindrome(string &str){
        int low=0, high=str.length()-1;
        while(low<=high){
            if(str[low]!=str[high]){
             return false;   
            }
            low++,high--;
        }
        return true;
    }
    void findAll(int ind, string &str,vector<string>&temp,vector<vector<string>>&ans){
        if(ind>=str.length()){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=ind;i<str.length();i++){
            string s=str.substr(ind,i-ind+1);
            if(isPallindrome(s)){
                temp.push_back(s);
                findAll(i+1,str,temp,ans);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        
        vector<string>temp;
        vector<vector<string>>ans;
        findAll(0,s,temp,ans);
        return ans;
    }
};