class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
     long long num=0;
    int store=x;
        while(x!=0){
            int l=x%10;
            num=num*10+l;
            x=x/10;
        }
        if(num==store)return true;
        return false;
    }
};