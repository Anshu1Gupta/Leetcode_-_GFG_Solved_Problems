class Solution {
public:
	int minOperations(vector<int>& nums) {
   	 vector<int>ans;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
         if(ans.size()==0||ans.back()!=nums[i]){
           ans.push_back(nums[i]);
         }
       }
       int right=0;
       int n=ans.size();
       int maxi=0;
       for(int left=0;left<n;left++){
           while(right<n&&(ans[right]-ans[left]<=(nums.size()-1))){
              right++;
           }
           int window_size=right-left;
           maxi=max(maxi,window_size);
       }


       return nums.size()-maxi;

	}
};


