class Solution {
public:
    void findOrder(int open,int close,vector<string>&ans,int n,string temp){
        if(temp.length()==2*n){
            ans.push_back(temp);
            return;
        }
        if(temp.empty()||open!=0)
        {
            temp+='(';
            findOrder(open-1,close,ans,n,temp);
            temp.pop_back();
        }
        if(!temp.empty()&&(close>open)){
            temp+=')';
            findOrder(open,close-1,ans,n,temp);
            temp.pop_back();
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        findOrder(n,n,ans,n,temp);
        return ans;
    }
};