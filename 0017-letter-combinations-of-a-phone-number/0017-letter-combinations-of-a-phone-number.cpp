class Solution {
public:
    void insert(unordered_map<char,string>&mp){
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        return;
    }
void findCombinations(int ind,string& digits,unordered_map<char,string>&mp,string &temp,vector<string>&ans)
{
    if(temp.size()==digits.size()){
        ans.push_back(temp);
        return ;
    }
    
    for(int i=ind;i<digits.size();i++){
        string str=mp[digits[i]];
        
        for(int j=0;j<str.size();j++){
           temp+=str[j];
           findCombinations(i+1,digits,mp,temp,ans);
           temp.pop_back();
        }
    }
    
}
    vector<string> letterCombinations(string digits) {
        string temp;
        
        vector<string>ans;
        unordered_map<char,string>mp;
        insert(mp);
        findCombinations(0,digits,mp,temp,ans);
        if(digits.size()==0)return {};
        return ans;
        
    }
};