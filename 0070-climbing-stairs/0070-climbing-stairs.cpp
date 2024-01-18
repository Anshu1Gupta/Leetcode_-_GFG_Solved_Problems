class Solution {
public:
    int climbStairs(int n) {
        
        int prev=0;
        int curr=1;
        
        for(int i=1;i<=n;i++){
            int store=prev+curr;
            prev=curr;
            curr=store;
            // curr=prev+curr;
        }
        return curr;
    }
};