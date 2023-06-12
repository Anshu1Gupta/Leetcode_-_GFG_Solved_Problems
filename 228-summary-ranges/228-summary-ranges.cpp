class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())return {};
        long long count=nums[0];
        int start=0;
        int end=1;
         
        vector<string>ans;
       
        nums.push_back(nums.back()+2ll);
        while(end<nums.size()){
            count++;
            if(nums[end]!=count){
               
                    string f=to_string(nums[start]);
                    string t=to_string(nums[end-1]);
                    if(start==end-1){
                        ans.push_back(f);
                    }
                    else{
                        f+="->";
                        f+=t;
                        ans.push_back(f);
                       
                    }
                        count=nums[end];
                        start=end;
                        
                
            }
            end++;
        }
        
        return ans;
    }
    
};