class Solution {
public:
    int isOperator(string str){
        if(str=="/"||str=="+"||str=="-"||str=="*")return 1;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(isOperator(tokens[i])){
               long long x=st.top();st.pop();
               long long y=st.top();st.pop();
                
                if(tokens[i]=="/"){
                            st.push(y/x);
                }
                if(tokens[i]=="+"){
                            st.push(y+x);
                }
                if(tokens[i]=="-"){
                            st.push(y-x);
                }
                if(tokens[i]=="*"){
                            st.push(y*x);
                }
            }
            else{
                long long nums=stoi(tokens[i]);
                st.push(nums);
            }
        }
        return st.top();
    }
};