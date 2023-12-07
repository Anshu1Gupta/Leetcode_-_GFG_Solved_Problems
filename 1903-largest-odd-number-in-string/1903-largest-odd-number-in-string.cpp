class Solution {
public:
    string largestOddNumber(string num) {
        
        
        while(num.size()){
            
            int val=num.back()-'0';
            if(val%2==0)num.pop_back();
            else break;
        }
        return num;
    }
};