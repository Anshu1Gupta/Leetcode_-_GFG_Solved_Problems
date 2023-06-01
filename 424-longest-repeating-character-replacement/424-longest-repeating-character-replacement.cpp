class Solution {
public:
    int characterReplacement(string str, int k) {
        unordered_map<char,int>mp;
        int low=0;
        int ans=0;
        int high=0;
        int n=str.length();
        while(high<n){
            mp[str[high]]++;
            
            int ele=high-low+1;
            int maxfre=0;
            for(auto it:mp){
                maxfre=max(maxfre,it.second);
                
            }
          if((ele-maxfre)>k){
              mp[str[low]]--;
              low++;
             
              // mp[str[low]]++;
          }
           else{
               ans=max(ans,ele);
              
           }
             high++;
        }
        return ans;
    }
};