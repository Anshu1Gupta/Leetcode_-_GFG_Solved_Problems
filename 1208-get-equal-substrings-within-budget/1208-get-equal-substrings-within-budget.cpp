class Solution {
public:
    int equalSubstring(string s, string t, int m) {
        int res = 0,beg=0,sum=0;
        for(int i=0;i<s.size();i++) {
            sum+=abs(s[i]-t[i]);
            while(sum>m) {
                sum-=abs(s[beg]-t[beg]);
                beg++;
            }
            res = max(res, i-beg+1);
        }
        return res;
    }
};