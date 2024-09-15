class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>v(0,s.size());
        int bitmask=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                bitmask^=16;
            }
            if(s[i]=='e')
            {
                bitmask^=8;
            }
            if(s[i]=='i')
            {
                bitmask^=4;
            }
            if(s[i]=='o')
            {
                bitmask^=2;
            }
            if(s[i]=='u')
            {
                bitmask^=1;
            }
            v.push_back(bitmask);
        }
        //for(auto it:v)cout<<it<<" ";
        //cout<<endl;
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            
            if(v[i]==0)
            {
                ans=max(ans,i+1);
            }
            if(mp.find(v[i])==mp.end())
            {
                mp[v[i]]=i;
            }
            else 
            {
                ans=max(ans,i-mp[v[i]]);
                //cout<<curxor<<" "<<i<<" "<<ans<<endl;
            }
        }
        return ans;
    }
};