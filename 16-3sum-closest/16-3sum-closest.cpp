class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int close=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(sum==target){
                    return sum;
                }
                
                if(abs(target-sum)<abs(target-close)){
                    close=sum;
                }
                if(sum<target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return close;
    }
};