class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>temp;
        
        for(int i=0;i<nums.size();i++){
            int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            
            if(ind==temp.size()){
                temp.push_back(nums[i]);
            }
            else{
                temp[ind]=nums[i];
            }
            
            if(temp.size()==3)return true;
        }
        return false;
        
    }
};