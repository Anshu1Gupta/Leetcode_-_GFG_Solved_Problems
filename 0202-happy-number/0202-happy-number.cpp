class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        
        mp[n]=1;
        while(n!=1){
            
            int num=0;
            while(n!=0){
                int digit=n%10;
                num=num+(digit*digit);
                n=n/10;
            }
            n=num;
            if(mp.find(n)!=mp.end())return false;
            mp[n]=1;
            
        }
        return true;
    }
};