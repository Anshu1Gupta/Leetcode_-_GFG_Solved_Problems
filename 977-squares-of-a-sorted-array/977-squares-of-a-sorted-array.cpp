class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int>ans;
        int pos=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                pos=i;
                break;
            }
        }
        if(pos==0||pos==-1){
            for(int i=0;i<nums.size();i++){
                nums[i]=nums[i]*nums[i];
               
            }
            if(pos==-1){
                reverse(nums.begin(),nums.end());
            }
             return nums;
        }
        else{
            int n=nums.size();
            int negind=pos-1;
            int posind=pos;
            while(negind>=0&&posind<n){
                if(abs(nums[negind])<=abs(nums[posind])){
                    ans.push_back(nums[negind]*nums[negind]);
                    negind--;
                }
                else{
                    ans.push_back(nums[posind]*nums[posind]);
                    posind++;
                }
            }
            while(negind>=0){
             ans.push_back(nums[negind]*nums[negind]);
                    negind--;
            }
            while(posind<n){
                ans.push_back(nums[posind]*nums[posind]);
                    posind++;
            }
            return  ans;
        }
        return nums;
    }
};