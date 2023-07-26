class Solution {
public:
    int kthFactor(int n, int k) {
        int num=sqrt(n);
        // cout<<num<<endl;
        
        for(int i=1;i<num;i++){
            if(n%i==0&&--k==0)return i;
        }
        for(int i=num;i<=n;i++){
            if((n%i)==0&&--k==0)return i;
        }
        
        return -1;
    }
};