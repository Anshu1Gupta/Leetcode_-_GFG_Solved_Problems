class Solution {
public:
    int characterReplacement(string str, int k) {
        vector<int>mp(26,0);
        int low=0;
        int ans=0;
        int high=0;
        int n=str.length();
        while(high<n){
            mp[str[high]-'A']++;
            
            int ele=high-low+1;
            int maxfre=0;
            for(auto it:mp){
                maxfre=max(maxfre,it);
                
            }
          if((ele-maxfre)>k){
              mp[str[low]-'A']--;
              low++;
            
          }
           else{
               ans=max(ans,ele);
           }
             high++;
        }
        return ans;
    }
};