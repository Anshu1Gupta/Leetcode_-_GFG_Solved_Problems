class Solution {
public:
    int minFlips(int a, int b, int c) {
        int sum=a+b;
        int count=0;
       for(int i=0;i<32;i++){
           int b1=(a&(1<<i));
           int b2=(b&(1<<i));
           int c1=(c&(1<<i));
           if((b1|b2)==c1){
               continue;
           }
           else if(b1!=0){
                 if(b1==b2){
                     count+=2;
                 }
                 else count++;
           }
           else if(b1==0){
               count++;
           }
           
       }
        // 1000
        return count;
    }
};