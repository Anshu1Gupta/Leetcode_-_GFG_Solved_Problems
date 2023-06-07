class Solution {
public:
    void findOrder(int open,int close,vector<string>&ans,int n,string temp){
        if(temp.length()==2*n){
            ans.push_back(temp);
            return;
        }
        if(temp.empty()||open!=0)
        {
            findOrder(open-1,close,ans,n,temp+'(');
        }
        if(!temp.empty()&&(close>open))
        {
            findOrder(open,close-1,ans,n,temp+')');
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        findOrder(n,n,ans,n,temp);
        return ans;
    }
};