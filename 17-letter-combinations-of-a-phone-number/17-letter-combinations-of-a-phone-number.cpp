class Solution {
public:
    void fund(int i,string &temp,vector<string>&store,vector<string>&ans,string digits){
        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }
        int d= digits[i]-48;
        string str=store[d];
        for(int j=0;j<str.length();j++){
            temp+=str[j];
            fund(i+1,temp,store,ans,digits);
            temp.pop_back();
            // fund(i+1,temp,store,ans,digits);
        }
        // for(auto it:store){}
    }
    vector<string> letterCombinations(string digits) {
        vector<string>store(10);
        store[2]="abc";
        store[3]="def";
        store[4]="ghi";
        store[5]="jkl";
        store[6]="mno";
        store[7]="pqrs";
        store[8]="tuv";
        store[9]="wxyz";
           
        vector<string>ans;
        string temp;
        if(digits.empty())return ans;
        fund(0,temp,store,ans,digits);
        return ans;
    }
};