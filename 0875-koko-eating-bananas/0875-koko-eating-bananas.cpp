class Solution {
public:
    bool findFind(vector<int>&nums,int capacity,int h){
        int initialHour=0;
        
       for(int i=0;i<nums.size();i++){
            int t=ceil(nums[i]/(capacity*1.0));
            initialHour+=t;
            if(initialHour>h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int low=1;
      int high=*max_element(piles.begin(),piles.end());
        int ans=h;
        int mid=-1;
        while(low<=high){
            int k=(low+high)/2;
            mid=k;
            if(findFind(piles,k,h)){
                ans=mid;
                high=k-1;
            }
            else{
                low=k+1;
             
            }
        }
        return ans;
    }
};