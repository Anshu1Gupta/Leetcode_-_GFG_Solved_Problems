class Solution {
public:
    int totalMoney(int n) {
        vector<int>arr;
        for(int i=0;i<7;i++)arr.push_back(i+1);
        
        int sum=0;
        int i=0;
        while(n--){
            sum+=arr[i]++;
            i=(i+1)%7;
        }
        return sum;
    }
};