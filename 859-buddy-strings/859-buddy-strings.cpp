class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length())return false;
        int n=s.length();
        int ind1=-1,ind2=-1;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(s[i]!=goal[i]){
                if(ind1==-1)ind1=i;
                else if(ind2==-1)ind2=i;
                else{
                    return false;
                }
            }
        }
        if(ind1!=-1&&ind2!=-1)
        {
            swap(s[ind1],s[ind2]);
        return s==goal;
        }
        else{
            if(ind1==-1&&ind2==-1&&mp.size()!=n)return true;
            return false;
        }
          
        
        
    }
};