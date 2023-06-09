class Solution {
public:
    double myPow(double x, int n) {
        int y=abs(n);
        double ans=1.0;
        while(y>0){
            if(y&1){
                ans*=x;
            }
            x*=x;
            y/=2;
        }
        return n<0?1/ans:ans;
        
    }
};