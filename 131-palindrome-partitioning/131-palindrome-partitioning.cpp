class Solution {
public:
        
bool isPallindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
void findPartition(int ind,string str, vector<string>&temp,vector<vector<string>>&ans){
    if(ind==str.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<str.size();i++){
        if(isPallindrome(str,ind,i)){
            temp.push_back(str.substr(ind, i - ind + 1));
            findPartition(i+1,str,temp,ans);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {


    vector<string>temp;
    vector<vector<string>>ans;
     findPartition(0,s,temp,ans);

    return ans;
}
};