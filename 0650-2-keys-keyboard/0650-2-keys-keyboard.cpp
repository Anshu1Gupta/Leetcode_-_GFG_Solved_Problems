class Solution {
public:
    int minSteps(int n) {
          int ops = 0;
        for(int fac = 2; fac <= n; fac++){
            while(n % fac == 0){
                ops+=fac;
                n /= fac;
            }
        }
        return ops;
    }
};